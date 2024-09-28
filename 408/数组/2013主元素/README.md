#  序列中的主元素

>[2013] 408算法题

## 题目描述

![](https://i-blog.csdnimg.cn/blog_migrate/cb941e53f281866ef3c78ba39acb6a37.png)



## 解题思路

以最考场最先能想到的方法来，我先能想到哈希表的实现。

### 哈希表

基于哈希表来统计每个元素在数组中出现的次数，并找出出现次数最多的元素。如果某个元素的出现次数超过了数组长度的一半（即 n/2*n*/2），那么这个元素就是主元素，否则就返回 -1。

#### 具体步骤：

1. 遍历`nums`时使用`hash[nums[i]]`记录每个元素出现的次数，其中`nums[i]`是`hash`数组的下标。
2. 遍历哈希表，找到出现次数最多的元素。
3. 检查该元素的出现次数是否大于数组长度的一半，如果是，返回该元素；否则返回 -1。

```cpp
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
```

这里再给出一个使用`STL`中的`unordered_map`的实现

```cpp
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
```

`hashmap`已经做到了时间和空间复杂度都是**O(n)**，还不是最优解，**但是在考场上就写最快想出来的思路，就算是暴力也拿分，暴力好计算第三问的复杂度**。



### Boyer-Moore 多数投票(最优解)

该算法基于一个关键观察：如果有一个元素在数组中出现次数超过一半，那么经过一次遍历，我们可以通过抵消非多数元素，最终保留多数元素。

#### **算法步骤**：

1. **阶段 1**：在第一次遍历数组时，使用一个 `flag` 变量记录当前候选主元素，并用 `count` 来记录当前候选元素的计数。当遇到与候选元素相同的元素时，增加 `count`，否则减少 `count`。当 `count` 变为 0 时，更新 `flag` 为当前元素，并将 `count` 重置为 1。
2. **阶段 2**：在第二次遍历中，再次遍历整个数组，检查 `flag` 元素的实际出现次数，确认其是否是主元素。如果它的出现次数大于 `n/2`，则返回该元素，否则返回 -1。

这个算法两个一维`for`循环，时间复杂度为**O(n)**，空间上只有`flag`和`count`，复杂度为**O(1)**

```cpp
int major1(const int *nums){
    size_t size = sizeof(nums); 
    int flag = nums[0];
    int count = 0;
    
    // 第一步：Boyer-Moore 投票算法，寻找候选元素
    for (int i = 1; i < size-1; i++) {
        if (flag == nums[i]) {
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

    // 第二步：验证候选元素是否是主元素
    if (count > 0) {
        count = 0;
        for (int i = 0; i < size ; i++) {
            if (flag == nums[i]) count++;
        }
    }
    
    // 如果候选元素出现次数大于 n/2，则返回该元素
    if (count > (size / 2)) {
        return flag;
    } else {
        return -1;
    }
}

```

