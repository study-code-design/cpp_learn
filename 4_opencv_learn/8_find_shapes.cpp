#include <opencv2/opencv.hpp>
#include <iostream>

// void plot_shapes()
// {
//     cv::Mat img(512,512,CV_8UC3,cv::Scalar(0,0,0));
//     cv::circle(img, cv::Point(100, 70), 50, cv::Scalar(255, 0, 0), cv::FILLED);
//     cv::rectangle(img, cv::Point(150, 150), cv::Point(200, 300), cv::Scalar(0, 255, 0), cv::FILLED);
//     cv::ellipse(img, cv::Point(350, 200), cv::Size(100, 50), 0, 0, 360, cv::Scalar(0, 0, 255), cv::FILLED);
//     //三角形
//     cv::Point pts[3];
//     pts[0] = cv::Point(400, 300);
//     pts[1] = cv::Point(500, 300);
//     pts[2] = cv::Point(450, 250);
//     cv::fillConvexPoly(img, pts, 3, cv::Scalar(255, 255, 0), cv::LINE_AA);
// }

void getCoutours(cv::Mat &imgDilate,cv::Mat &img)
{
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(imgDilate,contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    // cv::drawContours(img,contours,-1,cv::Scalar(255,255,255),cv::RETR_EXTERNAL,cv::Point(0,0));
    //现在我们需要过滤掉一些不必要的轮廓，比如太小的、太大的、不规则的等等。获取轮廓中心点，并计算轮廓的面积和周长。
    for (int i = 0;i<contours.size();i++)
    {
        auto area = cv::contourArea(contours[i]);
        std::vector<std::vector<cv::Point>> conPoly(contours.size());
        std::vector<cv::Rect> rects(contours.size());
        if (area >= 2000)
        {
            std::string obj_type;
            auto peri = cv::arcLength(contours[i],true);
            cv::approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            std::cout << "Contour " << i << " has " << conPoly[i].size() << " points and area " << area << std::endl;
            switch (conPoly[i].size())
            {
                case 3:
                    obj_type = "Triangle";
                    break;
                case 4:
                    obj_type = "Rectangle";
                    break;
                case 8:
                    obj_type = "circles";
                    break;
                default:
                    obj_type = "Unknown";
            }
            cv::drawContours(img,conPoly,i,cv::Scalar(255,0,255),2);
            rects[i] = cv::boundingRect(conPoly[i]);
            /**
             * boundingRect这个函数可以计算出一个矩形的边界框，其左上角和右下角的坐标。
             * 返回值是一个cv::Rect类型的对象，其成员变量有x、y、width、height。
             */
            std::cout << "Bounding rect " << i << " has " << rects[i].width << " x " << rects[i].height << std::endl;
            // cv::rectangle(img,rects[i],cv::Scalar(0,255,0),2);
            cv::rectangle(img,rects[i].tl(),rects[i].br(),cv::Scalar(0,255,0),2);
            /*
             * tl 左上角
             * br 右下角
             */
            cv::putText(img,obj_type,cv::Point(rects[i].x,rects[i].y-5),cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(255,255,0),1,cv::LINE_AA);
            std::cout << std::endl;


        };
    }

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
    resize(img, img, Size(0,0),0.5,0.5);
    Mat img_Gray,img_Blur,img_Canny,img_Dilate,img_Erode;
    cvtColor(img,img_Gray,COLOR_BGR2GRAY);
    GaussianBlur(img_Gray,img_Blur,Size(5,5),0);
    Canny(img_Blur,img_Canny,30,100);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(img_Canny,img_Dilate,kernel);
    erode(img_Dilate,img_Erode,kernel);
    getCoutours(img_Erode,img);
    imshow("Shapes", img);
    // imshow("Gray", img_Gray);
    // imshow("Blur", img_Blur);
    // imshow("Canny", img_Canny);
    // imshow("Dilate", img_Dilate);
    imshow("Erode", img_Erode);
    waitKey(0);
    destroyAllWindows();
    return 0;
}