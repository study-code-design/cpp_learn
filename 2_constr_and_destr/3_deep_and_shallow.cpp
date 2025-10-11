#include <iostream>
using namespace std;

class Person
{
public:
    Person(int a,int h)
    {
        m_A=a;
        height=new int(h);
        cout << "Person的有参构造函数调用" << endl;
    }
    Person(const Person &p)
    {
        m_A=p.m_A;
        // height = p.height; //浅拷贝
        height = new int (*p.height);//深拷贝
        cout << "Person的拷贝构造函数调用" << endl;
    }


    ~Person()
    {
        if(height!=nullptr)
        {
            delete height;
            height=nullptr;
        }
        cout << "Person的析构函数调用" << endl;
    }


    int m_A;
    int *height;
};



int main()
{
    Person p1(10,170);
    Person p2(p1);
    cout << "------------------" << endl;
    // 先进后出，析构函数调用两次，浅拷贝导致两次释放同一块内存
    
    cout << *p1.height << endl;
    cout << *p2.height << endl;
    return 0;
}