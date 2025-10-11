#include <iostream>

using namespace std;

int *func()
{
    // 如果不通过static修饰，函数返回局部变量的地址会导致悬空指针(栈区)，当然也可以通过new在堆区开辟内存（堆区)
    int *p = new int(10);
    // 数组
    int *arr = new int[10];
    arr[0] = 10;
    arr[1] = 20;
    return arr;
}

int main()
{
    int *arr = func();
    cout << "The value of a is: " << *arr << endl; // This will lead to undefined behavior
    delete[] arr; // 释放内存
    return 0;
}