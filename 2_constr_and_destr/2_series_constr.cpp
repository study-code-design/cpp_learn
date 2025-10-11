#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        
        cout << "Person的无参构造函数调用" << endl;
    }
    Person(int a,int b)
    {
        m_A=a;
        m_B=b;
        cout << "Person的有参构造函数调用" << endl;
    }
    Person(const Person &p)
    {
        m_A=p.m_A;
        m_B=p.m_B;
        cout << "Person的拷贝构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    void show()
    {
        cout << "m_A=" << m_A << endl;
        cout << "m_B=" << m_B << endl;
    }
    void setA(int a)
    {
        m_A=a;
    }
    void setB(int b)
    {
        m_B=b;
    }
private:
    int m_A;
    int m_B;


};


int main()
{   
    // Person p1;
    Person p2(10,20);
    Person p3(p2);
    cout << "------------------" << endl;
    p3.show();
    p3.setA(100);
    p3.setB(200);  
    cout << "------------------" << endl;
    p2.show();
    return 0;
}