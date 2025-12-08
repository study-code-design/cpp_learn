#include <opencv2/opencv.hpp>
#include <iostream>



void plot_shapes()
{
    cv::Mat img(512,512,CV_8UC3,cv::Scalar(0,0,0));
    cv::circle(img, cv::Point(100, 70), 50, cv::Scalar(255, 0, 0), cv::FILLED);
    cv::rectangle(img, cv::Point(150, 150), cv::Point(200, 300), cv::Scalar(0, 255, 0), cv::FILLED);
    cv::ellipse(img, cv::Point(350, 200), cv::Size(100, 50), 0, 0, 360, cv::Scalar(0, 0, 255), cv::FILLED);
    //三角形
    cv::Point pts[3];
    pts[0] = cv::Point(400, 300);
    pts[1] = cv::Point(500, 300);
    pts[2] = cv::Point(450, 250);
    cv::fillConvexPoly(img, pts, 3, cv::Scalar(255, 255, 0), cv::LINE_AA);
}

int main(int argc, char** argv) 
{
    using namespace cv;
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }
    std::string image_path = argv[1];
    
    Mat img = imread(image_path);

    imshow("Shapes", img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}