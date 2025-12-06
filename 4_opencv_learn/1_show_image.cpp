#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include "matplotlibcpp.h"
#include <vector>
#include <chrono>

using namespace std;
std::vector<int> v1 = {50,50,50,50};
namespace plt = matplotlibcpp;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    using namespace cv;
    cv::Mat img;
    img = imread("/home/tu/Desktop/ros_folder/cpp_learn/4_opencv_learn/1_base_img/lena.png");
    imshow("lena",img);
    
    vector<Mat> channels;
    split(img,channels);
    // imshow("B",channels.at(0));
    // imshow("G",channels[1]);
    // imshow("R",channels[2]);
    
    Mat replicate,reflect,wrap,constant;
    plt::figure(); 
    std::map<std::string, std::string> keywords;
    copyMakeBorder(img,replicate,v1[0],v1[1],v1[2],v1[3],cv::BORDER_REPLICATE);
    copyMakeBorder(img,reflect,v1[0],v1[1],v1[2],v1[3],cv::BORDER_REFLECT);
    copyMakeBorder(img,wrap,v1[0],v1[1],v1[2],v1[3],cv::BORDER_WRAP);
    copyMakeBorder(img,constant,v1[0],v1[1],v1[2],v1[3],cv::BORDER_CONSTANT,Scalar(0,0,0));
    plt::subplot(2,3,1);
    plt::imshow(replicate.ptr<uchar>(),replicate.cols,replicate.rows,replicate.channels(),keywords);
    plt::subplot(2,3,2);
    plt::imshow(reflect.ptr<uchar>(),reflect.cols,reflect.rows,reflect.channels(),keywords);
    plt::subplot(2,3,3);
    plt::imshow(wrap.ptr<uchar>(),wrap.cols,wrap.rows,wrap.channels(),keywords);
    plt::subplot(2,3,4);
    plt::imshow(constant.ptr<uchar>(),constant.cols,constant.rows,constant.channels(),keywords);
    plt::show();
    cout << img.cols << endl;
    cout << img.rows << endl;
    cout << img.channels() << endl;
    cout << typeid(img.size()).name() << endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "spend time: " << duration.count() << endl;

}