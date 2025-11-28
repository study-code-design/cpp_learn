//
// Created by tu on 2025/11/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
bool hasCommonElement(const std::vector<string>& vec1, const std::vector<string>& vec2) {
    std::set<string> elements(vec1.begin(), vec1.end()); // 将 vec1 的元素存入集合
    for (string num : vec2) {
        if (elements.find(num) != elements.end()) { // 检查 vec2 的元素是否存在于集合中
            return true; // 找到相同元素
        }
    }
    return false; // 没有相同元素
}
bool compareStr(string str1, string str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    int count = 0;
    for (int i=0; i<str1.size(); i++)
    {
        for (int j=0; j<str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                count++;
            }
        }
    }
    return  count == str1.size();

}

bool operator==(string str1, string str2)
{
    return compareStr(str1, str2);
}
vector<vector<string>> s2;

std::vector<vector<string>> func(vector<string> strs)
{
    vector<string> s1;
    vector<string> s_temp;
    for (int i=0; i<strs.size()-1; i++)
    {
        for (int j = i+1; j<strs.size(); j++)
        {
            if (strs[i] == strs[j])
            {
                auto it = std::find(s1.begin(), s1.end(), strs[i]);
                if (it != s1.end())
                {
                    s1.push_back(strs[j]);
                }
                else
                {
                    s1.push_back(strs[i]);
                    s1.push_back(strs[j]);
                }
            }
        }
        // auto it = std::find(s1.begin(), s1.end(), strs[i]);
        // if (it == s1.end())
        // {
        //     s1.push_back(strs[i]);
        // }
        if (s1.size()!=0)
        {
            s2.push_back(s1);
        }
        s1.clear();

    }
    for (std::vector<vector<string>>::iterator iter = s2.begin(); iter != s2.end(); iter++)
    {
        if (s_temp.empty())
        {
            s_temp = *iter;
            continue;
        }
        if (hasCommonElement(s_temp,*iter))
        {
            if (s_temp.size() >= iter->size())
            {
                s2.erase(iter);
            }

        }

        for (std::vector<string>::iterator it = s_temp.begin(); it != s_temp.end(); it++)
        {
            cout << *it << " ";

        }
        cout << endl;


        s_temp = *iter;
    }
    return s2;
}

int main()
{
    vector<string> str1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // for_each(str1.begin(), str1.end(),[](string str){cout<<str<<endl;});
    string str2 = "sba";
    string str3 = "bas";
    vector<vector<string>> s(func(str1));
    cout << s.size() << " " << s.capacity();
    cout << endl;

    for_each(s.begin(),s.end(),[](std::vector<string> &s1)
    {
        for_each(s1.begin(),s1.end(),[](string &s3)
        {
            cout << s3 << " ";
        });
        cout << endl;
    });



}