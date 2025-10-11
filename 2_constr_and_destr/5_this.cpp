#include <iostream>
using namespace std;
//成员变量和成员函数是分开存储的
// class Person
// {
// public:
//     int m_A;
//     int m_B;
//     static int m_C; // 静态成员变量，共享内存，不占p1里面的内存
//     void func() {} // 成员函数
// };
// int Person::m_C = 100; // 静态成员变量初始化
int a = 10;
class Person
{
public:
    Person(){}

    Person(int age)
    {
        // this 指针，指向调用成员函数的对象，在案例中，this指向p1
        // this指针是隐含在类的非静态成员函数中的
        this->age = age;
    }
    int age;
    Person &addAge(Person &p)
    {
        this->age +=   p.age; // this指针指向调用addAge的对象
        return *this; // 返回当前对象本身 *this代表当前对象也就是p2
    }
    static int height; // 静态成员变量

};

void test01()
{
    Person p1(18);
    Person p2(20);
    p2.addAge(p1).addAge(p1); // 链式编程思想，如果不使用引用函数返回的话，会返回一个临时对象，无法继续调用，使用后可以认为返回的是p2本身
    // (*p2.addAge(p1)).addAge(p1); 当使用使用函数指针时，可以这样写
    cout << "p1 age: " << p1.age << endl;
    cout << "p2 age: " << p2.age << endl;
}

int test02(int b)
{
    return a + b;
}

int Person::height = 180;
int main()
{
    int test_a = 10;
    
    Person p1(18);
    cout << ++test_a << endl; 
    cout << test_a << endl; 
    cout << Person::height++ << endl; 
    cout << Person::height << endl; 

    cout << "size of p: " << sizeof(p1) << endl; // 空类的大小是1
    cout << p1.age << endl;
    test01();
    cout << test02(10) << endl;
    for(int i=0; i<10; i++)
    {
        cout << "i: " << i << endl; // 静态成员变量类外访问
    }
    return 0;
}