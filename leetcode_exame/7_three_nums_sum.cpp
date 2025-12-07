//
// Created by tu on 25-12-6.
//
//
// Created by tu on 25-12-6.
//
#include <iostream>
#include <vector>


std::vector<std::vector<int>> three_nums_sum(std::vector<int> &nums_)
{
    std::vector<std::vector<int>> v;
    if (nums_.empty() || count(nums_.begin(), nums_.end(), 0) == nums_.size())
    {
        std::cout << "直接返回" << std::endl;
        return v;
    }
    int length = nums_.size();
    for (int i = 0;i<length-2;i++)
    {
        int x = nums_[i];
        if (i>0 && x == nums_[i-1])
        {
            continue;
        }
        int j = i+1;
        int k = length-1;
        while (j<k)
        {
            int s = x+nums_[j]+nums_[k];
            if (s>0) k--;
            else if (s<0) j++;
            else
            {
                v.push_back(std::vector<int>{x,nums_[j],nums_[k]});
                j++;
                while (j<k && nums_[j]==nums_[j-1])
                {
                    j++;

                }
                k--;
                while (j<k && nums_[k]==nums_[k+1])
                {
                    k--;
                }

            }
        }
    }
    return v;
}


int main()
{
    using namespace std;
    vector<int> nums{-1,0,1,2,-1,-4};
    sort(nums.begin(), nums.end());
    for_each(nums.begin(), nums.end(), [](int i){cout << i << " ";});
    cout << endl;
    vector v_test{three_nums_sum(nums)};
    for (auto &v : v_test)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
