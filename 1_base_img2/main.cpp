#include <iostream>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/opencv.hpp>

#include <chrono>

using namespace std;


int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    using namespace cv;
    cv::Mat img;
    img = imread("/home/tu/Desktop/ros_folder/cpp_learn/4_opencv_learn/1_base_img/lena.png",IMREAD_GRAYSCALE);
    // imshow("lena",img);
    // waitKey(10000);
    // destroyAllWindows();
    cout << img.cols << endl;
    cout << img.rows << endl;
    cout << img.channels() << endl;
    cout << typeid(img.size()).name() << endl;

    string videoPath = "/home/tu/Documents/xwechat_files/wxid_ub1aet3sccta22_8224/msg/video/2025-11/video.mp4";
    VideoCapture vc(videoPath);
    if (!vc.isOpened())
    {
        cout << "无法打开视频" << endl;
        return -1;
    }
    while (true)
    {
        Mat frame;
        if (!vc.read(frame)) break;
        frame = frame(cv::Rect(0,0,30,30));
        imshow("video frame",frame);
        int key = waitKey(30);
        if (key == 27)
        {break;}

    }
    vc.release();
    destroyAllWindows();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "spend time: " << duration.count() << endl;

}