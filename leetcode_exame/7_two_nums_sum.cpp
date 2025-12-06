//
// Created by tu on 25-12-6.
//
#include <iostream>
#include <vector>


std::vector<std::vector<int>> three_nums_sum(const int &target,std::vector<int> &nums_)
{
    int left = 0, right = nums_.size() - 1;
    std::vector<std::vector<int>> v;
    while (left < right)
    {
        if (nums_[left] + nums_[right] == target)
        {
            v.push_back(std::vector{nums_[left], nums_[right]});
            right--;
            left++;
        }
        else if (nums_[left] + nums_[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }

    }
    return v;
}


int main()
{
    using namespace std;
    int target = 9;
    vector<int> nums{-2,1,2,3,5,6,7,11,15};
    vector<vector<int>> v_test{three_nums_sum(target,nums)};
    for (auto &v : v_test)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
