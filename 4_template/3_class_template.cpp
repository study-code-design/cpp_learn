#include <iostream>
using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
    Person(NameType age,AgeType name)
    {
        this->age = age;
        this->name = name;
    }
    NameType age;
    AgeType name;

};

int main()
{
    Person<string,int> p1("Tom",18);
    cout << "name:" << p1.name << endl;
    cout << "age:" << p1.age << endl;
    return 0;
}
