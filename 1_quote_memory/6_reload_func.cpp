# include <iostream>
using namespace std;


void func()
{
    cout << "func called" << endl;
}

void func(int a=10)
{
    cout << "func(int a) called with a = " << a << endl;
}



int main()
{
    // func();
}