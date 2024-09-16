#include <iostream>
#include <format>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout,std::format,std::vector;

int major1(const int *nums){
    size_t size = sizeof(nums);

    int flag = nums[0];
    int count = 0;

    for (int i = 1; i < size-1; i++) {
        if (flag == nums[i]){
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                flag = nums[i];
                count = 1;
            }
        }
    }
    if (count > 0){
        count = 0;
        for (int i = 0; i < size ; i++) {
            if (flag == nums[i]) count++;
        }
    }
    if (count > (size/2)){
        return flag;
    } else {
        return -1;
    }
}

int major2(const int *nums){
    size_t size = sizeof (nums);

    int *hash = new int[size](); //记得加()初始化为0
    int flag{-1};

    for (int i = 0; i < size; i++) {
        hash[nums[i]]++; //以元素为下标，值加1
    }
    for (int j = 0; j < size - 1; j++) {

        if (hash[j] > (size / 2)) {
            flag = j;//值只要超过就记录下标
            break;
        }
    }
    delete[] hash;
    return flag;
}

int major_STL(const vector<int> &nums){
    size_t size{nums.size()};
    int flag{0},maxi{0};
    std::unordered_map<int,int> map;

    for (const int& num : nums) {
        map[num]++; //记录某个数字出现的个数
    }
    for (auto pair : map) { //auto pair 的类型是 pair<int,int>
        if (maxi < pair.second){
            flag = pair.first;  //原数组的元素，作为map的元素
            maxi = pair.second; //map元素对应的值（个数）
        }
    }
    if (maxi > (size / 2)) return flag;
    else return -1;
}


int main() {
    int nums1[] = {0,5,5,3,5,7,5,5};
    vector<int> nums2 {0,5,5,3,5,7,5,5};
    if (int flag = major2(nums1);flag == -1){
        cout << format("数组不存在主元素。");
    } else {
        cout << format("数组主元素为{}",flag);
    }
}
