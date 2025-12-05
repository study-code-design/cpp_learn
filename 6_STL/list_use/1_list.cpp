//
// Created by tu on 25-11-29.
//
#include <iostream>
#include <vector>
#include <string>

#include "printSTL.h"

int main()
{
    using namespace std;
    using namespace print_stl;
    list<int> l1{1,3,4,5,6};
    list<int> l2(l1.begin(),l1.end());
    vector<int> v{1,2,3,4,5,6};
    vector<string>v2{"a","b","c","d","e","f"};
    printList(l1);
    printList(l2);
    printVector(v);
    printVector(vector<string>{"a","b","c","d","e","f"});

}
