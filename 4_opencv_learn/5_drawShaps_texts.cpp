//
// Created by tu on 25-12-6.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "matplotlibcpp.h"
#include <iostream>
namespace plt = matplotlibcpp;
int main()
{
    using namespace cv;
    using namespace std;
    Mat img(512,512,CV_8UC3,Scalar(0,0,0));
    // circle(img,Point(256,256),100,Scalar(255,0,0),5);
    //如果需要填充的话
    // circle(img,Point(256,256),100,Scalar(255,0,0),-1);
    circle(img,Point(256,256),100,Scalar(255,0,0),FILLED);
    rectangle(img,Point(100,100),Point(300,300),Scalar(144,255,144),5);
    line(img,Point(100,100),Point(300,300),Scalar(255,255,255),5);
    //左边的1为字体大小，右边的1为字体厚度
    putText(img,"welcome to my world",Point(256,256),FONT_HERSHEY_SIMPLEX,0.7,Scalar(255,255,255),1);

    imshow("image",img);
    









    waitKey(3000);
    destroyAllWindows();
}