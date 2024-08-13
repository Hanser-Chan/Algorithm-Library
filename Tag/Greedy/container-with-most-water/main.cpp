#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

using std::vector;

int maxAreaBaoLi(vector<int>& height) {
    int area{0};

    for (int i = 0; i < height.size(); ++i) {
        for (int j = i; j < height.size(); ++j) {
            int minH{std::min(height[i],height[j])};
            int temp = minH * (j - i );
            area = std::max(area,temp);
        }
    }
    return area;
}

int maxArea(vector<int>& height) {
    int left{0},right{static_cast<int>(height.size() - 1)};
    int area{0};

    while (left != right) {
        int minH{std::min(height[left],height[right])};
        int temp = minH * (right - left);

        if (height[left] <= height[right]){
            left++;
        } else {
            right--;
        }
        area = std::max(area,temp);
    }
    return area;
}


int main() {
    vector<int> height1 {1,8,6,2,5,4,8,3,7};
    vector<int> height2 {1,1};

    std::cout << std::format("最大面积：{}，{}", maxArea(height1), maxArea(height2));
}
