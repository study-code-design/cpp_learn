#include <iostream>
#include <string>
#include <functional>
using namespace std;

void func2_(const string &s_,int left_,int right_,int &start_,int &maxlength_)
{
    while (s_[left_] == s_[right_] && left_>= 0 && right_<= s_.length())
    {
        if (int currentLength = right_-left_+1;currentLength>maxlength_)
        {
            maxlength_ = currentLength;
            start_ = left_;//start用于分割字符串起始位置
        }
        left_--;
        right_++;
    }
}


string longestPalindrome(const string &s_)
{
    if (s_.empty()) return "";
    int maxLength = 1;
    int start = 0;
    for (int center = 0; center < s_.length(); center++)
    {
        //如果最终结果为奇数的话
        func2_(s_,center,center,start,maxLength);
        func2_(s_,center,center+1,start,maxLength);
    }
    return s_.substr(start,maxLength);

}


int main()
{
    const string s1{"bbaabbc"};
    string s2 = longestPalindrome(s1);
    cout << s2 << endl;

}