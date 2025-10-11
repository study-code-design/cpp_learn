#include <iostream>
#include <cmath>
#include "point.h"
#include "circles.h"

int radius;
Point center;
const double pi=3.14;

void Circle::setCircle(double r,int a,int b)
{
    if(r<=0)
    {
        cout << "Radius must be positive." << endl;
        return;
    }
    radius=r;
    center.x=a;
    center.y=b;
}
bool Circle::isPointInside(const Point &p)
{
    int x = center.x;
    int y = center.y;
    int a = p.x;
    int b = p.y;
    int dis = sqrt(pow((a-x),2)+pow((b-y),2));
    return dis<=radius;
}

        
