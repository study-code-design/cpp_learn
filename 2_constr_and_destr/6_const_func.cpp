#include <iostream>
using namespace std;


class Person
{
public:
    Person() {}
    // this本质上是一个指针常量，指针指向不可被修改 Person * const this 加入const后变为 const Person * const this
    // const修饰成员函数，表示该成员函数不可以修改成员变量
    void showPerson() const
    {
        cout << "showPerson func" << endl;
        //age = 100; // const修饰成员函数，不能修改成员变量
        // this->age = 100; // this指针的本质是常量指针，const Person * const this //和上面一样
        this->b = 100; // mutable修饰的成员变量，可以在const成员函数中修改
    }
    int age;
    mutable int b;

    void func()
    {
        cout << "func" << endl;
    }


};

typedef struct Student
{
    int age;
    Student() {cout << "Student 构造函数调用" << endl;}
    void showStudent()
    {
        cout << "showStudent func" << endl;
    }
} ST; // 结构体中不能定义const成员函数

int main()
{
    const Person p1; // 常对象
    // p1.age = 100; // 常对象不可以修改成员变量
    p1.b = 100; // mutable修饰的成员变量，可以修改
    p1.showPerson(); // 常对象只能调用const成员函数


    //常对象只能调用const成员函数(常函数)
    p1.showPerson();
    // p1.func(); // 错误，常对象不能调用普通成员函数


    Student s1;
    return 0;
}