#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    
    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end()); // 排序后的字符串作为键
        map[key].push_back(str);
    }
    
    vector<vector<string>> result;
    for (auto& pair : map) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    vector<string> str1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(str1);
    
    cout << result.size() << endl; // 应该输出 3
    
    for (auto& group : result) {
        for (string& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}