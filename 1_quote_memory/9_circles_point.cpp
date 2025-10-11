#include <iostream>
#include <cmath>
using namespace std;
# include "point.h"
# include "circles.h"

// class Point
// {
//     public:
//         int x=0;
//         int y=0;
// };


// class Circle
// {
//     /*
//         1.获得圆的半径和圆心坐标
//         2.获取点到坐标
//         3.通过圆内的函数来判断点是否在圆内
//     */
//     private:
//         int radius;
//         Point center;
//         const double pi=3.14;
//     public:
//         void setCircle(double r,int a=0,int b=0)
//         {
//             if(r<=0)
//             {
//                 cout << "Radius must be positive." << endl;
//                 return;
//             }
//             radius=r;
//             center.x=a;
//             center.y=b;
//         }
//         bool isPointInside(const Point &p)
//         {
//             int x = center.x;
//             int y = center.y;
//             int a = p.x;
//             int b = p.y;
//             int dis = sqrt(pow((a-x),2)+pow((b-y),2));
//             return dis<=radius;
//         }
        
        
// };


int main()
{
    Circle circle;
    circle.setCircle(5,1,1);
    Point p;
    p.x=2;
    p.y=1;
    if(circle.isPointInside(p))
    {
        cout << "Point (" << p.x << ", " << p.y << ") is inside the circle." << endl;
    }
    else
    {
        cout << "Point (" << p.x << ", " << p.y << ") is outside the circle." << endl;
    }
    return 0;
}