#pragma once
#include <iostream>
#include <cmath>
#include "point.h"
using namespace std;

class Circle
{
    /*
        1.获得圆的半径和圆心坐标
        2.获取点到坐标
        3.通过圆内的函数来判断点是否在圆内
    */
    private:
        int radius;
        Point center;
        const double pi=3.14;
    public:
        void setCircle(double r,int a=0,int b=0);
      
        bool isPointInside(const Point &p);
       
        
        
};