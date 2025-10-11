#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        
        cout << "Person的无参构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    


};


int main()
{   
    Person p1;
    
    return 0;
}