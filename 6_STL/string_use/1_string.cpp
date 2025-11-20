#include <iostream>
#include <string>
using namespace std;

void test1()
{
    string s1("hello s1");
    cout << s1 << endl;
    const char *str = "hello world";
    string s2(str);
    cout << s2 << endl;
    string s3(s2);
    cout << s3 << endl;
    string s4(10,'a');
    cout << s4 << endl;
}

int main()
{
    test1();
}