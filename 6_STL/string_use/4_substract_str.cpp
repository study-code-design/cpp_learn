#include <iostream>
#include <string>
using namespace std;


void test1()
{
    string str = "abcdef";
    string sub_str = str.substr(1,3);
    cout << "subStr = " << sub_str << endl;
}

void test2()
{
    string str = "hello@email.com";
    int pos = str.find("@");
    cout << pos << endl;
    if(pos != -1)
    {
        str = str.substr(0,pos);
        cout << str << endl;
    }
    else 
    {
        cout <<"please input the email"<<endl; 
    }
}

int main()
{
    test1();
    test2();
}