//参考扫描全能王的思路，实现一个透视变换的功能

#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>

using namespace cv;
using namespace std;
Mat img_draw,img_original,img_draw_copy,img_wrap;
vector<Point2f> points;
void mouse_callback(int event, int x, int y, int flags, void* userdata)
{
    string text = format("(%d, %d)", x, y);
    if (points.size() == 4)
    {
        std::cout << "Points already added. Cannot add more points." << std::endl;  
        return;
    }
    if(thread t1,t2;event == EVENT_MOUSEMOVE)
    {
        img_draw_copy.copyTo(img_draw);
        circle(img_draw, Point(x, y), 5, Scalar(255, 0, 0), FILLED);
        t2 = thread([x,y,text](){putText(img_draw, text, Point(x, y), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 1);});
        t1 = thread([x,y](){line(img_draw, Point(0, y), Point(img_draw.cols, y), Scalar(255, 255, 255), 1);});
        t1.join();
        t2.join();
        line(img_draw, Point(x, 0), Point(x, img_draw.rows), Scalar(255, 255, 255), 1);
        imshow("Original Image", img_draw);
        waitKey(5);
    }
    else if(event == EVENT_LBUTTONUP && points.size() < 4)
    {
        points.push_back(Point2f(x, y));
        circle(img_draw_copy, Point2i(x,y), 5, Scalar(0, 255, 0), FILLED);
        putText(img_draw_copy, text, Point(x, y), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 255), 1);
        std::cout << "Point added: " << x << ", " << y << std::endl;
        imshow("Original Image", img_draw);
        waitKey(5); 
    }
    // else if(event == EVENT_MBUTTONUP)
    // {
    //     points.pop_back();
    //     img_original.copyTo(img_draw_copy);
    //     for_each(points.begin(), points.end(), [](Point2f p){
    //         string text = format("(%d, %d)", p.x, p.y);

    //         circle(img_draw_copy, Point2i(p.x,p.y), 5, Scalar(0, 255, 0), FILLED);
    //         putText(img_draw_copy, text, Point2i(p.x,p.y), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 255), 1);

    //         imshow("Original Image", img_draw);
    //         waitKey(5); 
            
    //     });

    // }
    else if(event == EVENT_RBUTTONDOWN)
    {
        img_original.copyTo(img_draw_copy);
        points.clear();
    }
  
    
}


Mat matrix;
int main()
{

    int w = 98;
    int h = 155;
    Mat img = imread("/home/fiz/Desktop/document/cpp_learn/4_opencv_learn/pictures/objects.jpg");
    if (img.empty())
    {
        cout << "Could not read the image: " << endl;
        return 1;
    }
    rotate(img, img, ROTATE_90_COUNTERCLOCKWISE);
    resize(img, img, Size(), 0.5, 0.5);
    img.copyTo(img_draw);
    img.copyTo(img_original);
    img.copyTo(img_draw_copy);
    imshow("Original Image", img_draw);

    // points = {Point2f(445, 308), Point2f(563, 416), Point2f(161, 462), Point2f(268, 621)};

    setMouseCallback("Original Image", mouse_callback);
    while (true)
    {
        auto key = waitKey(10) & 0xFF;
        if (key == 27 || points.size() == 4)
        {
            break;
        }
    }
    destroyWindow("Original Image");
    
    
    
    Point2f src[4] = {points[0], points[1], points[2], points[3]};
    Point2f dst[4] = {Point2f(0,0),Point2f(w,0),Point2f(0,h),Point2f(w,h)};
    for(const auto &p:points)
    {
        circle(img_original, Point2i(p.x,p.y), 10, Scalar(0, 255, 0), FILLED);
    }
    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img_original,img_wrap,matrix,Size(w,h));
    imshow("Warped Image", img_wrap);
    imshow("Original_Image", img_original);
    waitKey(0);
    destroyAllWindows();
    return 0;
}