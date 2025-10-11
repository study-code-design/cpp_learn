# include <iostream>
using namespace std;

int ShowValue(const int &val)
{
    // val = 100; // Error: cannot modify a const reference
    cout << "The value of a is: " << val << endl;
    return val;
}

//这样子可以正常运行，如果函数放在main后面就会报错
int func(int a,int b=20);

int func(int a=10,int b)
{
    return a+b;
}




int main()
{
    int a=10;
    int val=ShowValue(a);
    cout << func() << endl;
    cout << "The value of a in main is: " << a << endl;
    cout << "The value returned is: " << val << endl;
    return 0;
}
