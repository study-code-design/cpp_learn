#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout << "animal speak\n";
    }

    virtual ~Animal() = 0;

};
Animal::~Animal()
{
    cout << "virtual destructor speak\n";
}

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "cat speak\n";
    }
};


int main()
{
    Cat c;
    c.speak();
}
