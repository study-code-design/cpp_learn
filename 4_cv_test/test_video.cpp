// detect_lightbars_with_corners_filtered_with_join.cpp
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
        inRange(hsv, Scalar(0,  80, 80), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(160, 80, 80), Scalar(179, 255, 255), mask2);
        mask = mask1 | mask2;
    } else if (target == "blue") {
        inRange(hsv, Scalar(100, 80, 50), Scalar(130, 255, 255), mask);
    } else {
        inRange(hsv, Scalar(0,  80, 80), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(160, 80, 80), Scalar(179, 255, 255), mask2);
        Mat maskB;
        inRange(hsv, Scalar(100, 80, 50), Scalar(130, 255, 255), maskB);
        mask = mask1 | mask2 | maskB;
    }

    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5,5));
    morphologyEx(mask, mask, MORPH_CLOSE, kernel, Point(-1,-1), 2);
    morphologyEx(mask, mask, MORPH_OPEN, kernel, Point(-1,-1), 1);


    return mask;
}

static void sortPointsByY(vector<Point2f> &pts) {
    sort(pts.begin(), pts.end(), [](const Point2f &a, const Point2f &b){
        if (fabs(a.y - b.y) < 1e-6) return a.x < b.x;
        return a.y < b.y;
    });
}

static double angleBetween(const Point2f &a, const Point2f &b) {
    double dot = a.x*b.x + a.y*b.y;
    double na = sqrt(a.x*a.x + a.y*a.y);
    double nb = sqrt(b.x*b.x + b.y*b.y);
    if (na < 1e-6 || nb < 1e-6) return 180.0;
    double cosv = dot / (na*nb);
    cosv = max(-1.0, min(1.0, cosv));
    return fabs(acos(cosv) * 180.0 / CV_PI);
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

    // 原有阈值 保留
    const double MIN_CONTOUR_AREA = 80.0;
    const double MIN_ASPECT_RATIO = 1.0;
    const double MAX_ASPECT_RATIO = 30.0;
    const double MAX_ANGLE_DIFF = 20.0;
    const double MAX_HEIGHT_DIFF_RATIO = 0.35;
    const double MAX_CENTER_Y_DIFF = 30.0;
    const double MIN_CENTER_X_DIST_RATIO = 0.5;

    // 新增鲁棒性阈值
    const double MIN_LONG_SIDE_PIX = 12.0;     // 最小长边像素，防止太小噪声
    const double MIN_SOLIDITY = 0.55;          // solidity = area / hullArea
    const double MIN_EXTENT = 0.30;            // extent = area / boundingRectArea
    const double MAX_TOPBOTTOM_ANGLE_DIFF = 20.0; // 内侧顶/底边角度差容忍

    while (true) {
        if (!cap.read(frame) || frame.empty()) break;
        Mat mask = getColorMask(frame, TARGET_COLOR);

        // grayscale for brightness checks if需要
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // find contours
        vector<vector<Point>> contours;
        findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        Mat draw = frame.clone();

        struct LightBar {
            RotatedRect rrect;
            double area;
            float longSide;
            float shortSide;
            Point2f center;
            vector<Point2f> verts;
            // 形态特征
            double solidity;
            double extent;
        };

        vector<LightBar> candidates;
        for (size_t i = 0; i < contours.size(); ++i) {
            double area = contourArea(contours[i]);
            if (area < MIN_CONTOUR_AREA) continue;

            RotatedRect rrect = minAreaRect(contours[i]);
            Size2f sz = rrect.size;
            float w = sz.width, h = sz.height;
            if (w <= 0 || h <= 0) continue;
            float longSide = max(w,h), shortSide = min(w,h);
            float aspect = longSide / shortSide;
            if (aspect < MIN_ASPECT_RATIO || aspect > MAX_ASPECT_RATIO) continue;
            if (longSide < MIN_LONG_SIDE_PIX) continue; // 太小直接丢弃

            // solidity：area / convexHullArea
            vector<Point> hull;
            convexHull(contours[i], hull);
            double hullArea = fabs(contourArea(hull));
            double solidity = (hullArea > 1e-6) ? (area / hullArea) : 0.0;
            if (solidity < MIN_SOLIDITY) continue;

            // extent：area / boundingRectArea
            Rect brect = boundingRect(contours[i]);
            double extent = (brect.area() > 0) ? (area / (double)brect.area()) : 0.0;
            if (extent < MIN_EXTENT) continue;

            // 保存候选
            LightBar lb;
            lb.rrect = rrect; lb.area = area; lb.longSide = longSide; lb.shortSide = shortSide; lb.center = rrect.center;
            Point2f pts[4]; rrect.points(pts);
            lb.verts.assign(pts, pts+4);
            lb.solidity = solidity; lb.extent = extent;
            candidates.push_back(lb);

            // 画候选（帮助调试）
            drawContours(draw, contours, (int)i, Scalar(0,255,0), 1);
            for (int k=0;k<4;k++) line(draw, pts[k], pts[(k+1)%4], Scalar(255,0,0), 1);
        }

        // 两两配对并打分，只保留得分最高的一对（提高鲁棒性，减少多假配对）
        double bestScore = 0.0;
        pair<int,int> bestPair = {-1,-1};
        vector<Point2f> bestCorners;

        for (size_t i = 0; i < candidates.size(); ++i) {
            for (size_t j = i+1; j < candidates.size(); ++j) {
                const LightBar &L = candidates[i];
                const LightBar &R = candidates[j];

                // 高度相似
                double hDiffRatio = fabs(L.longSide - R.longSide) / max(L.longSide, R.longSide);
                if (hDiffRatio > MAX_HEIGHT_DIFF_RATIO) continue;
                double s_h = 1.0 - min(hDiffRatio / MAX_HEIGHT_DIFF_RATIO, 1.0);

                // 角度相似（使用 rrect.angle）
                float angleL = L.rrect.angle, angleR = R.rrect.angle;
                if (angleL < -90) angleL += 180; if (angleR < -90) angleR += 180;
                double angleDiff = fabs(angleL - angleR);
                if (angleDiff > MAX_ANGLE_DIFF) continue;
                double s_a = 1.0 - min(angleDiff / MAX_ANGLE_DIFF, 1.0);

                // center y 接近
                double centerYDiff = fabs(L.center.y - R.center.y);
                if (centerYDiff > MAX_CENTER_Y_DIFF) continue;
                double s_y = 1.0 - min(centerYDiff / MAX_CENTER_Y_DIFF, 1.0);

                // center x 距离合理（至少 MIN_CENTER_X_DIST_RATIO*minLong）
                double centerXDist = fabs(L.center.x - R.center.x);
                double minLong = min(L.longSide, R.longSide);
                double required = MIN_CENTER_X_DIST_RATIO * minLong;
                if (centerXDist < required) continue;
                // score 越大越好（>=1 表示远大于最小要求）
                double s_x = min(centerXDist / (required*2.0), 1.0);

                // 顶部/底部顶点取法（从 verts 选上两和下两）
                vector<Point2f> leftVerts = L.verts, rightVerts = R.verts;
                sortPointsByY(leftVerts);
                sortPointsByY(rightVerts);
                Point2f L_top = (leftVerts[0].x < leftVerts[1].x) ? leftVerts[0] : leftVerts[1];
                Point2f L_bot = (leftVerts[2].x < leftVerts[3].x) ? leftVerts[2] : leftVerts[3];
                Point2f R_top = (rightVerts[0].x > rightVerts[1].x) ? rightVerts[0] : rightVerts[1];
                Point2f R_bot = (rightVerts[2].x > rightVerts[3].x) ? rightVerts[2] : rightVerts[3];

                // 内侧顶/底边向量
                Point2f topEdge = R_top - L_top;
                Point2f botEdge = R_bot - L_bot;
                double topbotAngle = angleBetween(topEdge, botEdge);
                if (topbotAngle > MAX_TOPBOTTOM_ANGLE_DIFF) continue;
                double s_tb = 1.0 - min(topbotAngle / MAX_TOPBOTTOM_ANGLE_DIFF, 1.0);

                // solidity/extent 平均分
                double s_sol = (L.solidity + R.solidity) / 2.0; // 0..1
                double s_ext = (L.extent + R.extent) / 2.0;     // 0..1

                // 综合score（各项平均，权重可调）
                double score = (s_h + s_a + s_y + s_x + s_tb + s_sol + s_ext) / 7.0;

                if (score > bestScore) {
                    bestScore = score;
                    bestPair = {(int)i,(int)j};
                    bestCorners = { L_top, R_top, R_bot, L_bot }; // 左上 右上 右下 左下
                }
            }
        }

        // 只当 bestScore 足够大时认为检测到装甲（阈值可调）
        const double PAIR_SCORE_THRESH = 0.35; // 经验值，越高越严格
        if (bestPair.first != -1 && bestScore >= PAIR_SCORE_THRESH) 
        {
            // 绘制最佳配对的四角
            vector<Point2f> &c = bestCorners;
            for (int m = 0; m < 4; ++m) line(draw, c[m], c[(m+1)%4], Scalar(0,255,255), 2);
            Scalar cornerColors[4] = { Scalar(0,0,255), Scalar(0,255,0), Scalar(255,0,0), Scalar(255,255,255) };
            for (int m = 0; m < 4; ++m)
            {
                circle(draw, c[m], 6, cornerColors[m], -1);
                putText(draw, format("%d", m), Point((int)c[m].x+6, (int)c[m].y-6), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,255,255), 1);
            }
            putText(draw, format("Score: %.2f", bestScore), Point(10,30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0,255,255), 2);

            // --------- 新增：把选中的左右矩形的最左两个点与最右两个点连成一个矩形（joinedCorners） ---------
            int idxL = bestPair.first;
            int idxR = bestPair.second;
            if (idxL >= 0 && idxR >= 0 && idxL < (int)candidates.size() && idxR < (int)candidates.size()) {
                const auto &Lrect = candidates[idxL];
                const auto &Rrect = candidates[idxR];
                // 从 verts 中挑出最左的两个点（左矩形）和最右的两个点（右矩形）
                auto pick_two_leftmost = [](const vector<Point2f> &verts){
                    vector<Point2f> v = verts;
                    sort(v.begin(), v.end(), [](const Point2f &a, const Point2f &b){ return a.x < b.x; });
                    Point2f p0 = v[0], p1 = v[1];
                    if (p0.y < p1.y) return pair<Point2f,Point2f>(p0,p1);
                    else return pair<Point2f,Point2f>(p1,p0);
                };
                auto pick_two_rightmost = [](const vector<Point2f> &verts){
                    vector<Point2f> v = verts;
                    sort(v.begin(), v.end(), [](const Point2f &a, const Point2f &b){ return a.x < b.x; });
                    Point2f p2 = v[2], p3 = v[3];
                    if (p2.y < p3.y) return pair<Point2f,Point2f>(p2,p3);
                    else return pair<Point2f,Point2f>(p3,p2);
                };

                auto Lpair = pick_two_leftmost(Lrect.verts);
                auto Rpair = pick_two_rightmost(Rrect.verts);

                vector<Point2f> joinedCorners(4);
                joinedCorners[0] = Lpair.first;   // left top
                joinedCorners[1] = Rpair.first;   // right top
                joinedCorners[2] = Rpair.second;  // right bottom
                joinedCorners[3] = Lpair.second;  // left bottom

                // 绘制 joined 矩形（黄色粗线）
                for (int m = 0; m < 4; ++m) {
                    line(draw, joinedCorners[m], joinedCorners[(m+1)%4], Scalar(0,255,255), 4);
                    circle(draw, joinedCorners[m], 5, Scalar(0,0,255), -1);
                }
                putText(draw, "JoinedRect", Point((int)joinedCorners[0].x, (int)joinedCorners[0].y-10), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0,255,255), 2);
            }
            // --------- 新增结束 ---------
        }
        else
        {
            putText(draw, "No confident pair", Point(10,30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0,0,255), 2);
        }

        imshow("Mask", mask);
        imshow("Result", draw);
        char key = (char)waitKey(30);
        if (key == 27 || key == 'q' || key == 'Q') break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
