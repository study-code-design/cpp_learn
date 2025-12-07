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

    string img_path = "/home/tu/cpp_learn/4_opencv_learn/lena.png";
    Mat img,imgResize,imgCrop;
    img = imread(img_path);
    if (img.empty())
    {
        cout << "not found" << endl;
        return -1;
    }
    cout << "img.size():" << img.size() << endl;
    // resize(img,imgResize,Size(256,256));
    resize(img,imgResize,Size(),0.5,0.5);
    cout << "imgResize.size():" << imgResize.size() << endl;

    Rect roi(100,100,200,200);
    imgCrop = img(roi);
    cout << "imgCrop.size():" << imgCrop.size() << endl;
    cout << "imgCrop.channels():" << imgCrop.size() << endl;
    imshow("img", img);
    imshow("imgResize", imgResize);
    imshow("imgCrop", imgCrop);
    waitKey(0);
    destroyAllWindows();
}