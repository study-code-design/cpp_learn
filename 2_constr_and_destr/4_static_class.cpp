#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        m_A=200;
    }

    static int m_A;
private:
    static int  m_B;
};

int Person::m_B = 1000;// 错误，私有成员不能访问

// 使用static时，类内声明，类外初始化，因为他会在代码运行前就分配内存，所以需要一个全局变量来初始化
int Person::m_A=100;
int main()
{
    Person p1;
    
    cout << p1.m_A << endl;
}