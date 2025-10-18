#include <iostream>
using namespace std;

class base
{
public:
    base()
    {
        cout << "base构造" << endl;
    }
    ~base()
    {
        cout << "base析构" << endl;

    }
    int a;
    static int static_a;
protected:
    int b;
private:
    int c;
};
class Son1 : public base
{
    public:
    Son1()
    {
        cout << "Son1构造" << endl;
    }
    ~Son1()
    {
        cout << "Son1析构" << endl;

    }
    static int static_a;
    int d;
    // int a;
};
int base::static_a = 100;
int Son1::static_a = 200;
int main()
{
    Son1 s;
    
    s.a = 100;
    cout << base().a << endl;
    cout << s.a << endl;
    cout << Son1::static_a << endl;
    cout << s.base::static_a << endl;
}