#include <iostream>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Core>
using namespace std;
using namespace cv;
using namespace Eigen;

string& foo (){
    static string ass = "tian_ming" ;
    cout << "tian_ming s ass: " << ass <<endl;
    return ass;
}

int main()
{
    Mat img;
    Matrix3d m = Matrix3d::Random();
    Matrix3d ma = Matrix3d::Constant(1.2);
    MatrixXd mx = MatrixXd::Constant(3,3,1.2);
    cout << ma << "\n" << mx <<endl;
    // cout << m <<endl;
    string& ass_TM = foo();
    ass_TM = "TM no ass!";
    foo();
    // img = imread("/home/tu/Desktop/ros_folder/cpp_learn/4_cv_test/test.png");
    // resize(img,img,Size(0,0),0.5,0.5);
    // imshow("nb",img);
    // waitKey(0);

}