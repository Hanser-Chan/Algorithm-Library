# 寻找两个正序序列中位数

>[2011] 408统考算法题

使用`二分查找`的思路，分别为两个数组设置左右指针和中间指针。

```cpp
size_t left1{0},right1{nums1.size() - 1},mid1{};
size_t left2{0},right2{nums2.size() - 1},mid2{};
```

## 算法流程

1. 当两个数组的指针相等时停止循环。
2. 中间指针始终为`(left1 + right1) / 2`
3. 如果`nums1[mid1] < nums2[mid2]`，则将丢弃`nums1`的前半部分，丢弃`num2`的后半部分，反过来同理，即更新左或右指针到`mid`位置。
4. 当剩余元素为**奇数**时，要**注意左右指针的替换位置**，而且判断剩余需要注意`(left1 + right1) % 2 == 0`的时候为奇数**！！！**



## 完整实现

```cpp
#include <iostream>
#include <vector>
#include <format> //cpp20
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
```

## 算法评价

每次循环，代码通过计算两个数组的中点，并排除掉一半的元素，这类似于二分查找的过程。

- **每次迭代**：将问题规模减半，左右边界移动靠近中间，剩余元素数目减少约一半。
- **迭代次数**：由于每次迭代将问题规模减半，因此最多需要 log⁡nlog*n* 次迭代，其中 n*n* 是数组的长度。

因此，**时间复杂度**是 O(log⁡n)，其中 n是每个数组的长度。

时间复杂度**O(log n)**，空间复杂度**O(1)**。