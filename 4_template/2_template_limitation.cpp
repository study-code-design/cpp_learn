#include <iostream>
#include <string>
using namespace std;

//模板局限性
// 有些特定的数据类型，需要用具体的方式来实现
class Person
{
public:
    Person(int age,string name)
    {
        this->age = age;
        this->name = name;
    }
    int age;
    string name;

};


template <typename T>
bool myCampare(const T &a,const T &b)
{
    return a == b?true:false;
}

template<> bool myCampare(const Person &a,const Person &b)
{
    return a.age == b.age && a.name == b.name;
}

int main()
{
    cout << myCampare(1,2) << endl; // 输出 false
    Person p1(18,"Tom"),p2(18,"Tom");
    cout << myCampare(p1,p2) << endl; // 输出 true
    return 0;
}