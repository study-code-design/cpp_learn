#include <iostream>
#include <string>
#include <algorithm>#include <iostream>
#include <string>
#include <algorithm>

void expandAroundCenter(const std::string& s, int left, int right, int& start, int& maxLength) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = left; //start用于分割字符串起始位置
        }
        left--;
        right++;
    }
}

std::string longestPalindrome(std::string s) {
    if (s.empty()) return "";

    int start = 0, maxLength = 1;

    for (int center = 0; center < s.length(); center++) {
        // 奇数长度：以 center 为中心
        expandAroundCenter(s, center, center, start, maxLength);

        // 偶数长度：以 center 和 center+1 之间为中心
        expandAroundCenter(s, center, center + 1, start, maxLength);
    }

    return s.substr(start, maxLength);
}

int main() {
    using namespace std;
    std::string s1 = "babad";
    std::string s2 = "cbbd";
    std::string s3 = "a";
    std::string s4 = "ac";

    std::cout << "输入: \"" << s1 << "\" 输出: \"" << longestPalindrome(s1) << "\"" << std::endl;
    std::cout << "输入: \"" << s2 << "\" 输出: \"" << longestPalindrome(s2) << "\"" << std::endl;
    std::cout << "输入: \"" << s3 << "\" 输出: \"" << longestPalindrome(s3) << "\"" << std::endl;
    std::cout << "输入: \"" << s4 << "\" 输出: \"" << longestPalindrome(s4) << "\"" << std::endl;
    cout << longestPalindrome(string{"bbaabbc"}) << endl;
    return 0;
}