#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include <chrono>

using namespace std;
using namespace cv;

int main()
{
   
    string videoPath = "/home/tu/Documents/xwechat_files/wxid_ub1aet3sccta22_8224/msg/video/2025-11/video.mp4";
    VideoCapture vc(videoPath);
    if (!vc.isOpened())
    {
        cout << "无法打开视频" << endl;
        return -1;
    }
    while (true)
    {
        Mat frame;
        if (!vc.read(frame)) break;
        frame = frame(cv::Rect(0,0,30,30));
        imshow("video frame",frame);
        int key = waitKey(30);
        if (key == 27)
        {break;}

    }
    vc.release();
    destroyAllWindows();
}