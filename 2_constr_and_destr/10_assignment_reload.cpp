#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age = new int (age);
    }
    Person(const Person &p)
    {
        this->age = new int (*p.age);
    }
    void operator=(const Person &p)
    {
        if (age != NULL) delete age;age=NULL;
        this->age = new int (*p.age);

    }
    int *age;
    ~Person()
    {
        if (age != NULL) delete age; age=NULL;
    }

};
ostream &operator<<(ostream &cout,const Person & p)
{
    cout << *p.age;
    return cout;
}
int main()
{
    Person p1(18);
    Person p2(20);
    Person p3(p1);
    p1 = p2;
    cout << p1 << endl;
    cout << p2 << endl;

}