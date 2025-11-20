#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void test01()
{
    vector<vector<int>> v={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    for (vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        for (vector<int>::iterator it2=it->begin();it2!=it->end();it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();
}