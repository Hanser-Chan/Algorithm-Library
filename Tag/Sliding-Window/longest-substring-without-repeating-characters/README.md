# 无重复字符的最长子串

[Leetcode Q3](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/)

示例 :

>输入: s = "pwwkew"  
>
>输出: 3
>
>解释: 因为无重复字符的最长子串是 `"wke"`，所以其长度为 3。
> 
>请注意，你的答案必须是 子串 的长度，`"pwke"` 是一个子序列，不是子串。



题解：

```cpp
int lengthOfLongestSubstring(std::string s) {
    //不按特定顺序存储键值的关联式容器，其允许通过键值快速的索引到对应的元素。
    std::unordered_set<char> set;	
    int maxLength{0},left{0},right{0};
	//使用滑动窗口
    while (right < s.length()){
        if (set.find(s[right]) == set.end()){//在容器中找不到对应元素
            set.insert(s[right]);	//在容器中插入字符
            maxLength = std::max(maxLength, right - left + 1);
            ++right;	//扩大窗口
        } else {
            set.erase(s[left]);	//删除窗口最左边元素
            ++left;		//窗口向前滑动
        }
    }
    return maxLength;
}
```



