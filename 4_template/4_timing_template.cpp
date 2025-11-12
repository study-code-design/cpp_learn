#include <iostream>
using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "展示Person1\n";
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "展示Person2\n";
    }
};
template<class T>
class func
{
public:
    T obj;
    void func1()
    {
        obj.showPerson1();
    }

    void func2()
    {
        obj.showPerson2();
    }
};

int main()
{
    func<Person1> f;
    f.func1();
    // f.func2();
    return 0;
}
