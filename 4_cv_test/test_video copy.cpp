// detect_lightbars_with_corners.cpp
// 在原有的灯条检测代码基础上增加：
// 1) 对候选灯条两两配对，判断是否为装甲板的左右灯条
// 2) 从配对的两条灯条计算装甲板四个角点（左上 右上 右下 左下）
// 3) 在图像上显示灯条轮廓、最小外接矩形以及装甲板的四个角点（用圆点标出并连线）

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace cv;
using namespace std;

// 选择目标颜色 "red" 或 "blue" 或 "both"
const string TARGET_COLOR = "red";

Mat getColorMask(const Mat &bgr, const string &target) {
    Mat hsv;
    cvtColor(bgr, hsv, COLOR_BGR2HSV);

    Mat mask, mask1, mask2;
    if (target == "red") {
        // 红色在HSV是分两段的（0-10 和 160-180）
        inRange(hsv, Scalar(0,  80, 80), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(160, 80, 80), Scalar(179, 255, 255), mask2);
        mask = mask1 | mask2;
    } else if (target == "blue") {
        // 蓝色典型范围（需要根据视频调整）
        inRange(hsv, Scalar(100, 80, 50), Scalar(130, 255, 255), mask);
    } else { // both
        inRange(hsv, Scalar(0,  80, 80), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(160, 80, 80), Scalar(179, 255, 255), mask2);
        Mat maskB;
        inRange(hsv, Scalar(100, 80, 50), Scalar(130, 255, 255), maskB);
        mask = mask1 | mask2 | maskB;
    }

    // 小的形态学处理，去噪并连通灯条
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5,5));
    morphologyEx(mask, mask, MORPH_CLOSE, kernel, Point(-1,-1), 2);
    morphologyEx(mask, mask, MORPH_OPEN, kernel, Point(-1,-1), 1);

    return mask;
}

// 辅助：把点按 y 值升序排序（y 小在前）
static void sortPointsByY(vector<Point2f> &pts) {
    sort(pts.begin(), pts.end(), [](const Point2f &a, const Point2f &b){
        if (fabs(a.y - b.y) < 1e-6) return a.x < b.x; // y 相同则按 x
        return a.y < b.y;
    });
}

int main() {
    string videoPath = "/home/tu/Documents/xwechat_files/wxid_ub1aet3sccta22_8224/msg/video/2025-11/video.mp4";
    VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        cerr << "Error: Could not open video: " << videoPath << endl;
        return -1;
    }

    Mat frame;
    namedWindow("Result", WINDOW_NORMAL);
    namedWindow("Mask", WINDOW_NORMAL);

    // 可调参数（按需调整）
    const double MIN_CONTOUR_AREA = 80.0;      // 轮廓最小面积（像素）
    const double MIN_ASPECT_RATIO = 1.0;       // 灯条最小长宽比
    const double MAX_ASPECT_RATIO = 30.0;      // 灯条最大长宽比
    const double MAX_ANGLE_DIFF = 20.0;        // 成对灯条允许的最大角度差（度）
    const double MAX_HEIGHT_DIFF_RATIO = 0.35; // 灯条高度允许的相对差异
    const double MAX_CENTER_Y_DIFF = 30.0;    // 灯条中心 y 值允许的绝对差（像素）
    const double MIN_CENTER_X_DIST_RATIO = 0.5; // 两个灯条中心 x 距离相对于灯条长的最小比例

    while (true) {
        if (!cap.read(frame) || frame.empty()) break;

        Mat mask = getColorMask(frame, TARGET_COLOR);

        // find contours on mask
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        Mat draw = frame.clone();

        // 保存符合条件的灯条最小外接矩形
        struct LightBar {
            RotatedRect rrect;
            double area;
            float longSide;
            float shortSide;
            Point2f center;
            vector<Point2f> verts; // 4 顶点
        };

        vector<LightBar> candidates;

        for (size_t i = 0; i < contours.size(); ++i) {
            double area = contourArea(contours[i]);
            if (area < MIN_CONTOUR_AREA) continue; // 太小的噪声过滤掉

            // 最小外接旋转矩形
            RotatedRect rrect = minAreaRect(contours[i]);
            Size2f sz = rrect.size;
            float w = sz.width;
            float h = sz.height;
            if (w <= 0 || h <= 0) continue;
            float longSide = max(w, h);
            float shortSide = min(w, h);
            float aspect = longSide / shortSide;

            // 纵横比过滤（灯条通常是长条，纵横比大）
            if (aspect < MIN_ASPECT_RATIO || aspect > MAX_ASPECT_RATIO) continue;

            // 可选：按角度过滤（如果你知道灯条一般竖直或接近竖直）
            float angle = rrect.angle;
            // 规范角度到 [-90, 90]
            if (angle < -90) angle += 180;
            if (angle > 90) angle -= 180;
            // 不做强制角度过滤，但后面配对时会检查角度差

            // 绘制轮廓（绿色）和矩形（蓝色）
            drawContours(draw, contours, (int)i, Scalar(0, 255, 0), 2);
            Point2f verts[4];
            rrect.points(verts);
            for (int j = 0; j < 4; ++j) {
                line(draw, verts[j], verts[(j+1)%4], Scalar(255, 0, 0), 2);
            }
            circle(draw, rrect.center, 2, Scalar(0,0,255), -1);

            // 保存为候选灯条
            LightBar lb;
            lb.rrect = rrect;
            lb.area = area;
            lb.longSide = longSide;
            lb.shortSide = shortSide;
            lb.center = rrect.center;
            lb.verts.assign(verts, verts+4);
            candidates.push_back(lb);
        }

        // 对候选灯条做配对，找到可能的装甲板
        // 两条灯条配对条件示例：高度（长边）相近、角度接近、中心 y 接近、且中心 x 距离在合理范围
        vector<vector<Point2f>> detectedArmors; // 每个装甲板的 4 个角点

        for (size_t i = 0; i < candidates.size(); ++i) {
            for (size_t j = i+1; j < candidates.size(); ++j) {
                const LightBar &L = candidates[i];
                const LightBar &R = candidates[j];

                // 高度相似
                double hDiffRatio = fabs(L.longSide - R.longSide) / max(L.longSide, R.longSide);
                if (hDiffRatio > MAX_HEIGHT_DIFF_RATIO) continue;

                // 角度相似
                float angleL = L.rrect.angle;
                float angleR = R.rrect.angle;
                // 规范角度到 [-90,90]
                if (angleL < -90) angleL += 180; if (angleL > 90) angleL -= 180;
                if (angleR < -90) angleR += 180; if (angleR > 90) angleR -= 180;
                if (fabs(angleL - angleR) > MAX_ANGLE_DIFF) continue;

                // 中心 y 不偏移太多
                if (fabs(L.center.y - R.center.y) > MAX_CENTER_Y_DIFF) continue;

                // 中心 x 距离不能太小（确保是两侧灯条而非重叠）
                double centerXDist = fabs(L.center.x - R.center.x);
                double minLong = min(L.longSide, R.longSide);
                if (centerXDist < MIN_CENTER_X_DIST_RATIO * minLong) continue;

                // 确定哪条在左哪条在右
                const LightBar *leftBar = &L;
                const LightBar *rightBar = &R;
                if (L.center.x > R.center.x) { leftBar = &R; rightBar = &L; }

                // 从各自的 4 个顶点里找顶端两个（y 最小的两个）和底端两个（y 最大的两个）
                vector<Point2f> leftVerts = leftBar->verts;
                vector<Point2f> rightVerts = rightBar->verts;
                sortPointsByY(leftVerts);
                sortPointsByY(rightVerts);

                // leftVerts[0] & leftVerts[1] 是上边两个点（按 x 升序或降序决定左右）
                Point2f left_top = (leftVerts[0].x < leftVerts[1].x) ? leftVerts[0] : leftVerts[1];
                Point2f left_bottom = (leftVerts[2].x < leftVerts[3].x) ? leftVerts[2] : leftVerts[3];

                // rightVerts[0] & rightVerts[1] 是上边两个点
                Point2f right_top = (rightVerts[0].x > rightVerts[1].x) ? rightVerts[0] : rightVerts[1];
                Point2f right_bottom = (rightVerts[2].x > rightVerts[3].x) ? rightVerts[2] : rightVerts[3];

                // 组合成装甲板四个角点（左上 右上 右下 左下）
                vector<Point2f> armorCorners(4);
                armorCorners[0] = left_top;
                armorCorners[1] = right_top;
                armorCorners[2] = right_bottom;
                armorCorners[3] = left_bottom;

                // 简单几何验证：对角线长度与长/宽比等（可选）
                double widthTop = norm(armorCorners[1] - armorCorners[0]);
                double widthBottom = norm(armorCorners[2] - armorCorners[3]);
                double heightLeft = norm(armorCorners[3] - armorCorners[0]);
                double heightRight = norm(armorCorners[2] - armorCorners[1]);
                if (min(widthTop, widthBottom) < 10.0) continue; // 太窄的排除

                // 保存装甲
                detectedArmors.push_back(armorCorners);
            }
        }

        // 将检测到的装甲板画到图像上并显示四个角点
        for (size_t k = 0; k < detectedArmors.size(); ++k) {
            const vector<Point2f> &c = detectedArmors[k];
            // 画多边形（黄色）
            for (int m = 0; m < 4; ++m) {
                line(draw, c[m], c[(m+1)%4], Scalar(0, 255, 255), 2);
            }
            // 画四个角点（填充圆点，颜色不同以便区分）
            Scalar cornerColors[4] = { Scalar(0,0,255), Scalar(0,255,0), Scalar(255,0,0), Scalar(255,255,255) };
            for (int m = 0; m < 4; ++m) {
                circle(draw, c[m], 5, cornerColors[m], -1);
                // 显示索引和坐标
                string idx = format("%d", m);
                string coord = format("(%.0f,%.0f)", c[m].x, c[m].y);
                putText(draw, idx, Point((int)c[m].x+6, (int)c[m].y-6), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,255,255), 1);
                putText(draw, coord, Point((int)c[m].x+6, (int)c[m].y+12), FONT_HERSHEY_SIMPLEX, 0.4, Scalar(200,200,200), 1);
            }
        }

        imshow("Mask", mask);
        imshow("Result", draw);

        char key = (char)waitKey(30);
        if (key == 27 || key == 'q' || key == 'Q') break; // ESC 或 q 退出
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
