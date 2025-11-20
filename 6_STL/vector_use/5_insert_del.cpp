//
// Created by tu on 25-11-14.
//
#include <iostream>
#include  <vector>
#include <print_vector.h>
using namespace std;
void test1()
{
    std::vector<int> v1;
    v1.assign(10,3);
    v1.insert(v1.begin()+5,35);
    std::cout << v1;
}

int main()
{
    test1();
}