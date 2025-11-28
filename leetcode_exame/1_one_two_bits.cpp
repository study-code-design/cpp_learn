#include <iostream>
#include <vector>
#include <algorithm>
bool IsEvenNumber(std::vector<int> v)
{
    return v.size()%2==0;
}

bool OneBitsOrTwoBits(std::vector<int> &v)
{
    //如果是偶数的话，需要后面两位都是0
    if (!all_of(v.begin(),v.end(),[](int num){return num == 0 || num == 1;}))
    {
        std::cout << "请输入只有0或者1的vector\n";
        return false;
    }
    if(IsEvenNumber(v))
    {
        return v[v.size()-1] == 0 && v[v.size()-2] == 0;
    }
    else
    {
        return v.back() == 0;
    }
}
int main()
{
    using namespace std;
    std::vector<int> v1 = {1,1,2,0};
    // cout << v1.size() << endl;

    for(vector<int>::iterator it = v1.begin();it !=v1.end();it++)
    {
        // cout << *(v1.begin()) << endl;
        // cout << *it << endl;
    }
    // cout << IsEvenNumber(v1) << endl;
    cout << OneBitsOrTwoBits(v1) << endl;
    return 0;
}
