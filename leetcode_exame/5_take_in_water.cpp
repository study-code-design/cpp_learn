#include <algorithm>
#include <iostream>
#include <vector>

int Max_areas(std::vector<int>& height) {
    if (height.empty() || height.size() == 1) {
        return 0;
    }

    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_height = std::min(height[left], height[right]);
        int current_area = width * current_height;
        
        max_area = std::max(max_area, current_area);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}

int main() {
    using namespace std;
    vector<int> nums{1,8,6,2,5,4,8,3,7};
    cout << Max_areas(nums) << endl; // 测试用，实际使用时应该用完整的数组
    return 0;
}