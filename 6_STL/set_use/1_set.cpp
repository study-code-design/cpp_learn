//
// Created by tu on 25-11-30.
//
#include <iostream>
#include <set>
using namespace std;
void test01()
{
    std::set<int> s1{4,5,1,2,3};
//只用insert插入的方法，没有尾插
    s1.insert(3);
    s1.insert(2);
    s1.insert(1);
    for (const auto &i : s1)
    {
        cout << i << endl;
    }
}

int main()
{
    test01();
}