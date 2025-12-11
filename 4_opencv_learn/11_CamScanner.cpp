//
// Created by tu on 25-12-11.
//
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat img;
cv::VideoCapture cap;



void Video_Or_Picture(char **argv_)
{

    const int num__ = std::stoi(argv_[2]);
    if (num__ == 0)
    {
        img = cv::imread(argv_[1]);
    }
    else if (num__ == 1)
    {
        cap = cv::VideoCapture(argv_[1]);
    }
}
void imshow_(const std::string &name_, const cv::Mat &img_)
{
    cv::imshow(name_, img_);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void getContours_(cv::Mat &preImg_, cv::Mat &img_)
{
    std::vector<std::vector<cv::Point>> contours__;
    std::vector<std::vector<cv::Point>> conPoly__(contours__.size());
    cv::findContours(preImg_, contours__, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for (int i = 0; i < contours__.size(); i++)
    {
        int area__ = cv::contourArea(contours__[i]);
        std::cout << "area: " << area__ << std::endl;
        if (area__ > 300)
        {
            auto peri__ = cv::arcLength(contours__[i], true);
            cv::approxPolyDP(contours__[i], conPoly__[i], 0.02 * peri__, false);
            cv::drawContours(img_, contours__, i, cv::Scalar(255, 0, 0), 2);
        }
    }
    imshow_("contours", img_);
}

void pre_process(cv::Mat &pre_img_)
{

    cv::Mat img_gray__,img_blur__,img_canny__;
    cv::rotate(pre_img_, pre_img_, cv::ROTATE_90_COUNTERCLOCKWISE);
    cv::resize(pre_img_, pre_img_, cv::Size(), 0.5, 0.5);
    cv::cvtColor(pre_img_, img_gray__, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(img_gray__, img_blur__, cv::Size(9, 9), 0);
    cv::Canny(img_blur__, img_canny__, 20, 150);
    // imshow_("canny", img_canny__);
    getContours_(img_canny__, pre_img_);

}




int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <video url>/picture path"  << " 0/1 "<< std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        return -1;
    }

    using namespace cv;
    using namespace std;
    Video_Or_Picture(argv);
    if (!img.empty())
    {
        pre_process(img);
    }





}
