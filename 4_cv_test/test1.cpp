#include <iostream>
#include <opencv2/opencv.hpp>
#include <signal.h>
// #include "/home/tu/Desktop/document/cpp_learn/0_header_test/include/test1.h"
using namespace std;
using namespace cv;

void func(int signum)
{
    cout << "I have received signal " << signum << endl;
    exit(signum);
}

int main()
{
    for(int i=1; i<32; i++) {
        signal(i, func);
    }
    // cout << substract(3,4) << endl;
    Mat img;
    img = imread("/home/tu/cpp_learn/4_cv_test/test.png");
    resize(img,img,Size(0,0),0.5,0.5);
    imshow("nb",img);
    waitKey(0);

}