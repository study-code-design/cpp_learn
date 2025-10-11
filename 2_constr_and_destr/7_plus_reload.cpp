#include <iostream>
using namespace std;
class Person
{
    public:
    Person(int a=0,int b=0)
    {
        this->a = a;
        this->b = b;
    }
    Person operator+(Person &p)
    {
        Person temp;
        temp.a = this->a + p.a;
        temp.b = this->b + p.b;
        return temp;
    }
    Person operator+(int num)
    {
        Person temp;
        temp.a = this->a + num;
        temp.b = this->b + num;
        return temp;
    }
    
    int a;
    int b;
};

int main()
{
    Person p1(10,20);
    
    Person p2(30,40);
    Person p3 = p1+p2+10; //链式编程思想
    Person p4 = p1 + 100; //等价于上面一行
    cout << "p3.a=" << p3.a << endl;
    cout << "p3.b=" << p3.b << endl;
    cout << "p4.a=" << p4.a << endl;
    cout << "p4.b=" << p4.b << endl;


    return 0;
}