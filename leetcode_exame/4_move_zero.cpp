//
// Created by tu on 2025/11/27.
//
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <chrono>
#include <future>
int func(std::vector<int>& nums)
{

    std::thread t1([&nums](){sort(nums.begin(), nums.end());});
    std::future<long> result = std::async(std::launch::async,[&nums]()
    {
        return std::count_if(nums.begin(), nums.end(),[](int &i)
        {
            return i == 0;
        });
    });

   t1.join();
    return result.get();
}

int main()
{
    using namespace std;
    auto start = chrono::high_resolution_clock::now();
    vector<int> v{1,0,0,3,12};
    func(v);
    int num = func(v);
    cout << num << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
}