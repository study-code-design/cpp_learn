#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
Mat img,imgHsv,mask;
int hmin=0,hmax=180,smin=0,smax=255,vmin=0,vmax=255;
////

int main()
{
    string path = "/home/tu/cpp_learn/4_opencv_learn/pictures/green_ball.jpg";
    try
    {
        img = imread(path);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    resize(img,img,Size(),0.5,0.5);
    namedWindow("trackbars", (640,200));
    createTrackbar("H min","trackbars",&hmin,180,NULL);
    createTrackbar("H max","trackbars",&hmax,180,NULL);
    createTrackbar("S min","trackbars",&smin,255,NULL);
    createTrackbar("S max","trackbars",&smax,255,NULL);
    createTrackbar("V min","trackbars",&vmin,255,NULL);
    createTrackbar("V max","trackbars",&vmax,255,NULL);
    
    while(true)
    {
        

        Scalar lower(hmin, smin, vmin); //hsv min values
        Scalar upper(hmax, smax, vmax); //hsv max values
        cvtColor(img, imgHsv, COLOR_BGR2HSV);
        inRange(imgHsv,lower,upper,mask);

        namedWindow("HSV Image", WINDOW_AUTOSIZE);
        imshow("HSV Image", imgHsv);
        // imshow("Mask", mask);
        imshow("trackbars",mask);
        if(waitKey(1)==27)
        {
            break;
        }
    }
    return 0;
}