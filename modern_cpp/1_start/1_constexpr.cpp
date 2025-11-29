//
// Created by tu on 2025/11/28.
//
#include  <iostream>
#include <vector>
#include <initializer_list>
# define LEN 10
//init list

void func(const std::vector<int> &vec)
{
    // std::for_each(vec.begin(),vec.end(),[](int &i){std::cout<<i<<" ";});
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    using namespace std;
    constexpr int len = 10+2+3;
    constexpr int len2 = LEN +2;
    char arr1[len];
    char arr2[len2];
    //2.2 variable initialize
    std::vector<int> vec{1,2,3,4};
    func({1,2,3,4});
    if (const std::vector<int>::iterator &it = std::find(vec.begin(), vec.end(), 1);it != vec.end())
    {
        *it = 4;
    }
    for_each(vec.begin(),vec.end(),[](int &i){std::cout<<i<<" ";});
}