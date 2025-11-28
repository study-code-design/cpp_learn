//
// Created by tu on 2025/11/27.
//
#include <iostream>
#include <algorithm>
#include <vector>

int func(std::vector<int>& nums)
{
    std::vector<int>::iterator count = std::count_if(nums.begin(),nums.end(),[](int i)
    {
        return i == 0;
    });

    return count;
}

int main()
{
    using namespace std;
    vector<int> v{0,1,0,3,12};
    int num = func(v);
    cout << num << endl;
}