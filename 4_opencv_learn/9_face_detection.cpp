//
// Created by tu on 25-12-10.
//
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    std::string url = "http://192.168.1.252:8080/video";
    VideoCapture cap(url);
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    while (true)
    {
        Mat frame;
        cap.read(frame);
        transpose(frame,frame);
        flip(frame,frame, 1);
        cvtColor(frame, frame, COLOR_BGR2GRAY);
        if(frame.empty())
        {
            std::cout << "End of video stream" << std::endl;
            break;
        }
        imshow("Video", frame);
        if(waitKey(20) == 27)
        {
            break;
        }

    }

}
