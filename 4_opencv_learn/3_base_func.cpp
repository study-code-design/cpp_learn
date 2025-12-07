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

    Mat img, imgGray,imgBlur,imgCanny,imgDilate,imgErode;
    string img_path = "/home/tu/cpp_learn/4_opencv_learn/lena.png";
    img = imread(img_path);

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img,imgBlur,Size(3,3),5,0);
    Canny(imgBlur, imgCanny, 50, 150);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny, imgDilate, kernel);
    erode(imgDilate, imgErode, kernel);
    

    if (img.empty())
    {
        cout << "not found" << endl;
        return -1;
    }
    
    // imshow("img", img);
    // imshow("imgGray", imgGray);
    // imshow("imgBlur", imgBlur);
    // imshow("imgCanny", imgCanny);
    imshow("imgDilate", imgDilate);
    imshow("imgErode", imgErode);
    


    waitKey(0);
    destroyAllWindows();
}