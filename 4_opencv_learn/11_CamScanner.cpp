//
// Created by tu on 25-12-11.
//
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#define width 210
#define height 297
void pre_processing(cv::Mat &img_);
void wrap_image_(std::vector<std::vector<cv::Point>> &ang_points_,cv::Mat &img_);
void getContours_(cv::Mat &process_img_,cv::Mat &ori_img_);




int main(int argc,char** argv)
{
    if (argc != 2)
    {
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <video url>/picture path"  << " 0/1 "<< std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        return -1;
    }
    using namespace std;
    using namespace cv;
    string path = argv[1];
    Mat img = imread(path,IMREAD_COLOR_BGR);
    pre_processing(img);
}


void pre_processing(cv::Mat &img_)
{
    using namespace cv;
    Mat pre_img,img_gray,img_blur,img_canny;
    pre_img = img_.clone();
    cvtColor(pre_img,img_gray,COLOR_BGR2GRAY);
    GaussianBlur(img_gray,img_blur,Size(9,9),0);
    Canny(img_blur,img_canny,20,150);
    getContours_(img_canny,pre_img);

}

void getContours_(cv::Mat &process_img_,cv::Mat &ori_img_)
{
    using namespace cv;
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(process_img_,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    std::vector<std::vector<Point>> conPoly(contours.size());
    std::vector<Rect> boundRect(contours.size());
    for (int i = 0;i < contours.size();i++)
    {
        int area = contourArea(contours[i]);
        if (area > 4000 || conPoly[i].size() == 4)
        {
            std::cout << "area = " << area << std::endl;
            double peri = arcLength(contours[i],true);
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            drawContours(ori_img_,conPoly,i,Scalar(0,0,255),2);
            std::cout << conPoly[i].size() << std::endl; //角点个数
        }

    }
    wrap_image_(conPoly,ori_img_);

}

void wrap_image_(std::vector<std::vector<cv::Point>> &ang_points_,cv::Mat &img_)
{
    using namespace cv;
    Mat img_wrap;
    for (auto &ang : ang_points_)
    {
        if (ang.size() == 4)
        {
            Point2f src[4]={ang[0],ang[3],ang[1],ang[2]};
            Point2f dst[4] = {Point2f(0,0),Point2f(width,0),Point2f(0,height),Point2f(width,height)};
            for (int i = 1;const auto &p: src)
            {
                circle(img_,p,10,Scalar(0,255,255));
                putText(img_,std::to_string(i++),p,FONT_HERSHEY_COMPLEX,2,Scalar(0,255,0));
            }


            Mat matrix = getPerspectiveTransform(src,dst);
            warpPerspective(img_,img_wrap,matrix,Size(width,height));
            imshow("wrap",img_wrap);
            imshow("ori",img_);
            waitKey(0);
            destroyAllWindows();
        }
    }
}