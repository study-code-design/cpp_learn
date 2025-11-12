#include <iostream>
// #include <opencv2/opencv.hpp>
// #include <eigen3/Eigen/Core>
#include <vector>
using namespace std;
// using namespace cv;
// using namespace Eigen;




int main()
{
    std::vector<std::vector<float>> data = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (auto row : data) {
        std::cout << "Row: " << row[0] << " " << row[1] << " " << row[2] << std::endl;
        for (auto val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        
    }
    
}