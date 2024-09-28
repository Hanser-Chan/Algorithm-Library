#include <iostream>
#include <vector>
#include <format>
#include <algorithm>

using std::vector;

int middle(vector<int> &nums1, vector<int> &nums2){
    size_t left1{0},right1{nums1.size() - 1},mid1{};
    size_t left2{0},right2{nums2.size() - 1},mid2{};

    while (left1 != right1 || left2 != right2){

        mid1 = (left1 + right1) / 2;
        mid2 = (left2 + right2) / 2;

        if (nums1[mid1] == nums2[mid2]) return nums1[mid1];

        if (nums1[mid1] < nums2[mid2]){ //1 < 2
            if ((left1 + right1) % 2 == 0) { //奇数
                left1 = mid1;
                right2 = mid2;
            } else {
                left1 = mid1 + 1;
                right2 = mid2;
            }
        } else { //1 > 2
            if ((left1 + right1) % 2 == 0) { //奇数
                right1 = mid1;
                left2 = mid2;
            } else {
                left2 = mid2 + 1;
                right1 = mid1;
            }
        }
    }
    return std::min(nums1[right1],nums2[right2]);
}

int main() {
    vector<int> v1{11,13,15,17,19};
    vector<int> v2{2,4,6,8,20};

    std::cout << std::format("中位数是{}", middle(v1,v2));
}
