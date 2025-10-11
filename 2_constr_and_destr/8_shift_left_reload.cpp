#include <iostream>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &cout,Person &p);
     
    private:
    Person(int a=0,int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    int a;
    int b;
};
ostream &operator<<(ostream &cout,Person &p)
{
    cout << p.a << endl;
    cout << p.b << endl;
    return cout;
};


int main()
{
    Person p1 = Person(10,20);
    cout << p1 << endl;
}