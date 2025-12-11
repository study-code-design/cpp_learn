//
// Created by tu on 25-12-10.
//
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int hmin=0,hmax=180,smin=0,smax=255,vmin=0,vmax=255;
void on_trackbar(int, void*) {}
void findThresholds()
{
    namedWindow("Thresholds", WINDOW_NORMAL);
    resizeWindow("Thresholds", 640, 200);

    // 使用NULL作为value指针，并设置回调函数
    createTrackbar("Hmin", "Thresholds", NULL, 180, on_trackbar);
    createTrackbar("Hmax", "Thresholds", NULL, 180, on_trackbar);
    createTrackbar("Smin", "Thresholds", NULL, 255, on_trackbar);
    createTrackbar("Smax", "Thresholds", NULL, 255, on_trackbar);
    createTrackbar("Vmin", "Thresholds", NULL, 255, on_trackbar);
    createTrackbar("Vmax", "Thresholds", NULL, 255, on_trackbar);

    // 设置初始值
    setTrackbarPos("Hmin", "Thresholds", hmin);
    setTrackbarPos("Hmax", "Thresholds", hmax);
    setTrackbarPos("Smin", "Thresholds", smin);
    setTrackbarPos("Smax", "Thresholds", smax);
    setTrackbarPos("Vmin", "Thresholds", vmin);
    setTrackbarPos("Vmax", "Thresholds", vmax);
}


void findColor(Mat &frame)
{

}


int main(int argc, char** argv)
{

    std::string url = "http://192.168.1.252:8080/video";
    VideoCapture cap(url);
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }
    Mat mask;
    // findThresholds();
    while (true)
    {
        Mat frame;
        cap.read(frame);
        transpose(frame,frame);
        flip(frame,frame, 1);
        if(frame.empty())
        {
            std::cout << "End of video stream" << std::endl;
            break;
        }
        // hmin = getTrackbarPos("Hmin", "Thresholds");
        // hmax = getTrackbarPos("Hmax", "Thresholds");
        // smin = getTrackbarPos("Smin", "Thresholds");
        // smax = getTrackbarPos("Smax", "Thresholds");
        // vmin = getTrackbarPos("Vmin", "Thresholds");
        // vmax = getTrackbarPos("Vmax", "Thresholds");
        Scalar lower(20, 91, 81);
        Scalar upper(66, 255, 255);
        cvtColor(frame, frame, COLOR_BGR2HSV);
        inRange(frame, lower, upper, mask);
        imshow("Video", frame);
        imshow("mask", mask);
        if(waitKey(20) == 27)
        {
            break;
        }

    }

}
