//
// Created by tu on 25-12-6.
//
// #include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
// #include <opencv2/imgproc.hpp>
#include <iostream>

int main()
{
    using namespace cv;
    using namespace std;

    Mat img;
    string img_path = "/home/tu/cpp_learn/4_opencv_learn/lena.png";
    img = imread(img_path, IMREAD_COLOR);
    if (img.empty())
    {
        cout << "not found" << endl;
        return -1;
    }
    
    imshow("img", img);
    waitKey(0);
    destroyAllWindows();
}