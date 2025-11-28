//
// Created by tu on 2025/11/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <set>

std::set<int> Vector_To_Set(const std::vector<int> &v)
{
    std::set<int> s(v.begin(),v.end());
    return s;
}

int sortNum(std::vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    std::vector<int> v1;
    int count1 = 1;
    std::ranges::sort(nums.begin(), nums.end());
    std::set<int> s1 = Vector_To_Set(nums);
    std::vector<int> v_erase_similarity(s1.begin(),s1.end());
    for_each(v_erase_similarity.begin(),v_erase_similarity.end(),[](int i){std::cout << i << std::endl;});
    for (int i = 0;i<v_erase_similarity.size()-1;i++)
    {
        // std::cout << v_erase_similarity[i] << " ";
        if (abs(v_erase_similarity[i+1]-v_erase_similarity[i]) == 1)
        {
            count1++;
        }
        else
        {
            v1.push_back(count1);
            count1 = 1;
        }
    }
    v1.push_back(count1);

    std::cout << std::endl;
    std::vector<int>::iterator max_count = std::max_element(v1.begin(), v1.end());
    return *max_count;
}

int main()
{
    using namespace std;
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> nums = {100,4,200,1,3,2};
    cout << sortNum(nums) << endl;


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << duration.count() << endl;
}