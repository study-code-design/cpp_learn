//
// Created by tu on 25-11-29.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "printSTL.h"

void vector_test()
{
    using namespace std;
    vector<int> v1{0,0,3,3,1};
    v1.reserve(10);
    print_stl::print(v1);
    v1.erase(v1.begin());
    print_stl::print(v1);
    cout << "v1容量:" << v1.capacity() << " v1.size:" << v1.size() << endl;
    v1.shrink_to_fit();
    cout << "v1容量:" << v1.capacity() << " v1.size:" << v1.size() << endl;

    // v1.push_back(1,2,3)

}
void list_test()
{
    using namespace std;
    list<int> l;

    l.emplace_back(1);
    l.emplace_back(1);
    l.emplace_back(1);
    l.emplace_front(3);
    l.emplace_front(3);
    l.emplace_front(3);
    print_stl::print(l);
    std::cout << "l size: " << l.size() << std::endl;
    l.remove(3);
    std::cout << "l size: " << l.size() << std::endl;
    print_stl::print(l);
    auto it = l.begin();
    std::advance(it,3);
    print_stl::print(l);
    cout << *it << endl;
    auto num = find(l.begin(),l.end(),1);



}


int main()
{
    // vector_test();
    list_test();
}
