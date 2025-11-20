#include <iostream>
#include <thread>
#include <vector> 
#include <chrono>
#include "print_vector.h"
using namespace std;

// void test1()
// {
//     vector<int> v1(10);
//     for (int i = 0; i < 10; i++)
//     {
//         v1[i]=i;
//     }
//     cout << v1;
//
// }
// void test2()
// {
//     vector<int> v1(10);
//     for (int i = 0; i < 10; i++)
//     {
//         v1[i]=i;
//     }
//     cout << v1;
//
// }
void test1()
{
    vector<int> v1(1000000);  // 改成100万
    for (int i = 0; i < 1000000; i++)
    {
        v1[i] = i * i;  // 加点计算
    }
    long long sum = 0;
    for (auto x : v1) sum += x;
    cout << sum << endl;
}

void test2()
{
    vector<int> v1(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        v1[i] = i * i * i;
    }
    long long sum = 0;
    for (auto x : v1) sum += x;
    cout << sum << endl;
}
void test3()
{
    vector<int> v1;
    for (int i = 0; i < 1000000; i++)
    {
        v1.push_back(i * i);
    }
    cout << "v的容量为" << v1.capacity() << endl;
    cout << "v的大小为" << v1.size() << endl;
    v1.resize(3);
    cout << "v的容量为" << v1.capacity() << endl;
    cout << "v的大小为" << v1.size() << endl;
    //使用swap；来收缩内存
    /*vector<int>()这个是一个匿名的对象,当传入v1时
     *调用了里面的拷贝构造函数
     *执行完这一行后被系统直接回收掉了
     */
    vector<int>(v1).swap(v1);
    cout << "v的容量为" << v1.capacity() << endl;
    cout << "v的大小为" << v1.size() << endl;

}
int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    thread t1(test1);
    thread t2(test2);
    thread t3(test3);
    t1.join();
    // test3();
    // thread t2(test2);
    t2.join();
    // test1();
    // test2();
    t3.join();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "用时:" << elapsed.count() << endl;
}