#include <iostream>
using namespace std;


class Cube
{
    /*
        1.对于一个长方体来说，需要得到他的长宽高，当然还需要申明pi
        2.初次之外，需要写两个方法来分别计算出体积和表面积
        3.最后在main函数中进行测试
    
    */

    private:
        double length;
        double width;
        double height;
        const double pi = 3.14159;
    public:
        int t;
        void setCube(double l, double w, double h)
        {   
            if(l <= 0 || w <= 0 || h <= 0)
            {
                cout << "Length, width, and height must be positive values." << endl;
                return;
            }
            length = l;
            width = w;
            height = h;
        }
        double getVolume()
        {
            return length * width * height;
        }
        double getSurfaceArea()
        {
            return 2 * (length * width + width * height + height * length);
        }

        bool CubeEqual(const Cube &other)
        {
            return (length == other.length) && (width == other.width) && (height == other.height);
        }
    
};


int main()
{
    Cube cube1,cube2;
    cube1.t=10;
    cube1.setCube(3.0,4.0,5.0);
    cube2.setCube(3.0,3.0,5.0);
    if(cube1.CubeEqual(cube2))
    {
        cout << "The two cubes are equal." << endl;
    }
    else
    {
        cout << "The two cubes are not equal." << endl;
    }
    cout << "t: " << cube1.t << endl;
    cout << "t: " << cube2.t << endl;
    cout << "Volume: " << cube1.getVolume() << endl;
    cout << "Surface Area: " << cube1.getSurfaceArea() << endl;
}