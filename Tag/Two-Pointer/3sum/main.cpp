#include <iostream>
#include <vector>
#include <format>
#include <algorithm>

using std::vector,std::format;

vector<vector<int>> threeSum(vector<int>& nums) {
    size_t len {nums.size()-1};

    std::sort(nums.begin(),nums.end());

    vector<vector<int> > res;

    for (size_t i = 0; i < len - 1; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        size_t left{i + 1},right{nums.size() - 1};

        while (left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0){
                res.push_back({nums[i] , nums[left] , nums[right]});

                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;--right;

            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }

        }
    }
    return res;
}

int main() {
    vector<int> num1{-1,0,1,2,-1,-4};
    vector<int> num2{0,1,1};
    vector<int> num3{0,0,0};

    std::cout << format("有以下三元组\n") ;

    for (auto n : threeSum(num1)) {
        std::cout << "[";

        for (auto x : n) {
            std::cout << format("{}, ",x);
        }

        std::cout << "]";
    }
}
