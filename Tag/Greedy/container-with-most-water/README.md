#  盛最多水的容器

> [LEETCODE Q11](https://leetcode.cn/problems/container-with-most-water/description/)


给定一个长度为`n`的整数数组`height` 。有`n`条垂线，第`i`条线的两个端点是`(i, 0)`和`(i, height[i])`。

找出其中的两条线，使得它们与`x`轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

示例 1：

![1](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

>输入：[1,8,6,2,5,4,8,3,7]
>
>输出：49
> 
>解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：

>输入：height = [1,1]
> 
>输出：1


提示：

- `n == height.length`
- `2 <= n <= 105`
- `0 <= height[i] <= 104`

------- 
# 思路

1. 利用`双指针`, 分别指向头尾,遍历时向数组中间挤,相等时停止。
```c++
int left{0},right{static_cast<int>(height.size() - 1)};
int area{0};

while (left != right) {
```

2. 更新
    - 哪个指针指向的数字小，哪个就往中间走一步。
    - 面积更新为`max( area, min( h[l], h[r] ) * ( r - l ) )`
```c++
//循环内
int minH{std::min(height[left],height[right])}; //找短板
int temp = minH * (right - left); //底乘高

if (height[left] <= height[right]){ //更新
    left++;
} else {
    right--;
}
area = std::max(area,temp);
```
