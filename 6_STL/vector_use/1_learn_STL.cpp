
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end(); //结束迭代器，指向最后一个元素的下一个位置
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    cout << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
    for_each(v.begin(),v.end(),[](const int i){cout << i << " ";});
}