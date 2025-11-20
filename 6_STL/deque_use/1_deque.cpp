#include <iostream>
#include <deque>
#include <vector>
#include <chrono>
using namespace std;


int main()
{
    auto start =  chrono::high_resolution_clock::now();
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    for_each(d1.begin(), d1.end(), [](const int &i){cout << i << " ";});
    deque<int> d2(d1.begin(), d1.end());
    for_each(d2.begin(), d2.end(), [](const int &i){cout << i << " ";});
    vector<int> v(d1.size());



    auto end   = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout<<endl;
    cout << elapsed.count() << " ns" << endl;
}