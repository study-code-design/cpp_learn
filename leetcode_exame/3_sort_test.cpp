//
// Created by tu on 2025/11/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
int count1 = 0;
int &sortNum(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    auto temp = std::min_element(nums.begin(), nums.end());
    std::cout << *temp << std::endl;
    std::cout << typeid(*temp).name() << std::endl;

    return count1;
}

int main()
{
    using namespace std;
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << sortNum(nums) << endl;


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << duration.count() << endl;
}