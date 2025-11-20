#include <iostream>
using namespace std;

void test1()
{
    string s1("abcdea");
    int pos = s1.find("ab");
  //如果找到返回第一个遇到的值的下表，否则返回-1
    cout << pos << endl;
   //rfind从右往左找
    pos = s1.rfind("be");
}
void test2()
{
    string s1("abcdea");
    s1.replace(1,3,"1234");
    cout << s1 << endl;
}
int main()
{
    test1();
    test2();
}