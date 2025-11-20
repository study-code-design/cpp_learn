#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;
std::mutex mtx;

void test2()
{
    string s1 = "hello world111";
    std::lock_guard<mutex> lock(mtx);
    cout << s1 << endl;
    string s2;
    s2.assign(s1,6);
    cout << s2 << endl;
}

void test1()
{
    string s1 = "hello world";
    std::lock_guard<mutex> lock(mtx);
    cout << s1 << endl;
}

int main()
{
    thread t1(test1);
    thread t2(test2);
    t1.join();
    // cout << t1.get_id() << endl;
    // cout << t2.get_id() << endl;
    // cout << endl;
    t2.join();
}