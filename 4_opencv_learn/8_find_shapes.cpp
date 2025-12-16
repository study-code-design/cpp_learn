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
cv::Mat img_Gray,img_Blur,img_Canny,img_Dilate,img_Erode;
int main(int argc, char** argv)
{
    using namespace cv;
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }
    std::string image_path = argv[1];
    std::cout << image_path << std::endl;
    Mat img = imread(image_path);
    if (img.empty()) {
        std::cout << "Error: Image not loaded properly!" << std::endl;
        return -1;
    }
    cvtColor(img,img_Gray,COLOR_BGR2GRAY);

    GaussianBlur(img_Gray,img_Blur,Size(5,5),0);
    Canny(img_Blur,img_Canny,25,75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(img_Canny,img_Dilate,kernel);


    // imshow("Shapes", img);
    // imshow("Gray", img_Gray);
    // imshow("Blur", img_Blur);
    imshow("Canny", img_Canny);
    // plt::imshow(img_Canny);
    // plt::show();
    waitKey(0);
    destroyAllWindows();
    return 0;
}