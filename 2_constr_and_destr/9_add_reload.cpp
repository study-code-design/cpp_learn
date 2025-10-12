#include <iostream>
using namespace std;

class MyInteger
{
    friend ostream &operator<<(ostream&cout, const MyInteger&m_num);
public:
    MyInteger(int num)
    {
        this->num = num;
    }
    MyInteger &operator++()
    {
        num++;
        return *this;
    }
    MyInteger operator++(int)
    {
        MyInteger temp = *this;
        num++;
        return temp;
    }
private:
    int num;
    
};

ostream &operator<<(ostream&cout, const MyInteger&m_num)
{
    cout << m_num.num;
    return cout;
}


void test01()
{
    int a = 0;
    ++(++a);
    
    cout << a << endl;

}
int main()
{
    MyInteger m(10);
    MyInteger m1(0);
    // test01();
    cout << ++(++m) << endl; //如果不再22行加上const修饰，这个会报错，因为这个是一个临时变量(右值)
    cout << m << endl;
    cout << (m1++)++ << endl;
    cout << m1 << endl;

}