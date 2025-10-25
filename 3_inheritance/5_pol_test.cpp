# include <iostream>

using namespace std;
class Base
{
public:
    virtual void func() = 0;
};

class test:public Base
{
public:
    void func() override
    {
        cout << "test::func()" << endl;
    }
};

int main()
{
    Base *b = new test();
    b->func(); // This line will cause a compilation error because Base is an abstract class

    return 0;
}
