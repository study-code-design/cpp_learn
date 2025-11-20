#include <iostream>
#include <vector>
#include "print_vector.h"
using namespace std;

// template <typename T=int>
// ostream &operator<<(ostream &cout,const vector<T> &v)
// {
//     for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;
//     return cout;]
// }
void test1()
{
    vector<int> v = {1,2,3,4,5};
    vector<int> v2(v);
    vector<string> v1 = {"111","222","333","444"};
    cout << v;
    cout << v1;
}

int main()
{
    test1();
    cout << "hello" << endl;
}