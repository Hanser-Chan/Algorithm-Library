# 寻找链表倒数第k个元素

## 题目描述

已知一个带有表头结点的`单链表`，结点结构为 `data|next`。

假设该链表只给出了头指针list。在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点（k为正整数）。若查找成功，算法输出该结点的data值，并返回1；否则，只返回0。



## 解题思路

由于单链表只能存放下一结点的指针，我们并不能从后往前找。而找到倒数第k个，最简单的思路是：

- 遍历并记录链表长`l`，再从前往后找`l - k`次即可找到该元素。

这个思路最好想，并且时间复杂最坏也是**`O(n) + O(n-k) = O(n)`**。

```cpp
int CountList(Linklist &L) {
    int count{1};
    LNode *p = L;

    while (p->next != nullptr){
        p = p->next;
        count++;
    }
    cout << "计数完成\n";
    return count;
}


ElemType FindK1(Linklist &L,int k){
    cout <<"findk1\n";
    int count{CountList(L)}; //第一遍遍历链表
    count -= k;

    LNode *p = L;
    while (count > 0){  //第二遍遍历
        p = p->next;
        count--;
    }
    return p->data;
} //整体遍历两次
```



那我们根据这个思路可以进行优化到只遍历一遍链表：

1. 使用两个指针`*p,*q`同时指向`list`，
2. `p`先前进`k`步，然后`p,q`再一起前进。
3. 当`p`走到底，`q`刚好停在倒数第`k`个位置。

这样走下来比第一个思路要减少1次遍历。时间复杂也是**`O(n)`**。

```cpp
T FindK(LLNode* L, int k){
    cout << "findk2\n";
    LLNode *p = L;
    LLNode *q=  L;
    for (int i = 1; i < k; i++) {
        p = p->next;
    }
    while (p->next != nullptr){ //当p到达k时，pq同时后移
        p = p->next;
        q = q->next;
    }
    return q->data;
}
```



## 算法评价

两种算法都为**O(n)**。