#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age,int height)
    {
        this->age = new int (age);
        this->height = height;
    }
    Person(const Person &p)
    {
        this->age = new int (*p.age);
        this->height = height;
    }
    Person &operator=(const Person &p)
    {
        if (age != NULL) delete age;age=NULL;
        this->age = new int (*p.age);
        return *this;
    }
    bool operator==(const Person &p) const
    {
        if(*(this->age) == *(p.age) && this->height == p.height) return true;
        else return false;
        
        
    }
    int *age;
    int height;
    ~Person()
    {
        if (age != NULL) delete age; age=NULL;
    }

};
class Phone
{

};
ostream &operator<<(ostream &cout,const Person & p)
{
    cout << *p.age << endl;
    cout << p.height;
    return cout;
}

int main()
{
    Person p1(30,180);
    Person p2(30,180);
    Phone p3;
    cout << Person(10,20) << endl;
    cout << (p1 == p2) << endl;
}