#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <chrono>
std::vector<int> move_zero(std::vector<int>& nums)
{

  /* if nums.size() == 1 return
   * if nums.size*( == 2 reserver
   * 0. count_if
   * 1.v -> l
   * 2.l.remove(0)
   * 3.l -> v
   * 4. v.sort
   * 5. v.push_back
   */
    auto count_zero = std::count_if(nums.begin(), nums.end(), [](int &i) { return i == 0; });
    if (count_zero == nums.size() || count_zero == 0 || nums.empty() || nums.size() == 1)
    {
        return nums;
    }
    else if (nums.size() == 2)
    {
        if (nums[1] == 0)
        {
            return nums;
        }
        std::iter_swap(nums.begin(), std::prev(nums.end()));
        return nums;
    }
    std::list<int> l(nums.begin(), nums.end());
    l.remove(0);
    nums.assign(l.begin(), l.end());
    // std::sort(nums.begin(), nums.end());
    for (int i = 0; i < count_zero; i++)
    {
        nums.push_back(0);
    }
    return nums;

}
std::vector<int> moveZeroes(std::vector<int>& nums)
{
    int stack_size = 0;
    for(int x : nums){
        if(x) nums[stack_size++] = x;
    }
    std::fill(nums.begin() + stack_size, nums.end(), 0);
    return nums;

}
int main()
{
    using namespace std;
    auto start = chrono::high_resolution_clock::now();
    list<int> l;
    vector<int> v{4,2,4,0,0,3,0,5,1,0};
    // vector<int> v2 = move_zero(v);
    vector<int> v3 = moveZeroes(v);
    // for_each(v2.begin(), v2.end(), [](int &i) { cout << i << " "; });
    cout << endl;
    for_each(v3.begin(), v3.end(), [](int &i) { cout << i << " "; });
    cout << endl;
    vector<int> v4{1,3,0,5,-1};
    for (auto &i : v4)
    {
        if (i)
        {
            cout << i << " ";
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "所用时间：" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

}







>>>>>>> feature/main_1
