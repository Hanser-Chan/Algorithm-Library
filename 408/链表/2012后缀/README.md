# 找到两个链表的共同部分

>[2012] 408统考算法题
>
>⚠️本代码只实现了算法，暂未实现插入相同后缀时共享存储空间。

## 题目描述

假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀存储空间，例如，“loading”和“being”的存储映像如下图所示。

![Q](https://i-blog.csdnimg.cn/blog_migrate/e916b3fee8d0dcaa30b000585de42ed0.png)

## 解题思路

>❗️这里只用找到共同的结点，而不是找到共同的数据后缀，后者更复杂。

1. 双重循环枚举，两个`for`找到相同结点即可。时间复杂：$O(n^2)$

2. 找到同一起跑线。

   让长的变短，再同步出发寻找相同结点。

```
loading
being
找到同一起跑线->
loading
  being
```

令`*p=L1, *q=L2`，让长的链表先往前走`size(长的)-size(短的)`，此时同步，一起往后遍历链表，当`p == q`时即找到。

```cpp
LLNode* FindNode(LLNode* L1, LLNode* L2) {
    if (L1 == nullptr || L2 == nullptr) {
        return nullptr;  // 如果任何一个链表为空，返回空
    }

    int s1 = LLNode::count(L1);  // 计算第一个链表的长度
    int s2 = LLNode::count(L2);  // 计算第二个链表的长度

    LLNode* p = L1;
    LLNode* q = L2;

    // 对齐两个链表的起点
    if (s1 > s2) {
        for (int i = 0; i < s1 - s2; i++) {
            p = p->next;
        }
    } else if (s2 > s1) {
        for (int i = 0; i < s2 - s1; i++) {
            q = q->next;
        }
    }

    // 同时遍历两个链表，寻找公共节点
    while (p != nullptr && q != nullptr) {
        if (p == q) {
            return p;  // 找到公共节点
        }
        p = p->next;
        q = q->next;
    }

    return nullptr;  // 没有找到公共节点
}
```



## 算法评价

1. 双循环时间复杂$O(n^2)$
2. 同一起跑线复杂度**O(n)**。