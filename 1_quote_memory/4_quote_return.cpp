# include <iostream>

using namespace std;

int& test01()
{
    int *a = new int(50);
    return *a;
}

int main() {
    int &a = test01();
    cout << "The value of a is: " << a << endl; // This will lead to undefined behavior
    delete &a; // 释放内存
    return 0;
}