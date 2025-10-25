#include <iostream>
#include <vector>

using namespace std;


int main()
{
    // vector<int> arr={1,2,3,4,5};
    // cout << arr[1] << endl;
    // vector<int> arr2;
    // for(int i=0;i<10;i++)
    // {
    //     arr2.push_back(i);
    // }
    // cout << arr2.size() <<endl;
    //      string  s( "hello world" );
    //  for (auto c:s)
    //  c= 't' ;
    //  cout<<s<<endl; //结果为hello world
    //  for (auto &c:s)
    //  c= 't' ;
    //  cout<<s<<endl;  //结果为ttttttttttt
    // for (auto c:arr2)
    // {
    //     c = 1;
    //     arr2.push_back(c);
    //     cout << c << endl;
    // }
    vector<vector<int>> arr3_big;
    int count = 0;
    for(int i=0;i<10;i++)
    {
        vector<int> arr3_test;
        for(int j=0;j<10;j++)
        {
            arr3_test.push_back(count);
            count++;
        }
        arr3_big.push_back(arr3_test);
    }
    for(auto c:arr3_big)
    {
        cout << c[1] << endl;
    }
    return 0;
}
