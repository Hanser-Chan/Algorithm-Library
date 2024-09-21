//
// Created by JJC on 2024/9/21.
//

#include "ChainList.h"

bool InitList(Linklist &L) {
    L = new LNode;
    L->next = nullptr;
    return true;
}


void FillList(Linklist &L){
    ElemType flag;
    L = new LNode;
    L->next = nullptr;

    LNode *r = L;
    cin >> flag;

    while (flag != 9999){
        LNode *s = new LNode ;
        s->data = flag;
        s->next = nullptr;
        r->next = s;
        r = s;
        cin >> flag;
        if (cin.fail()) {
            cout << "输入错误，请输入正确的数字。" << std::endl;
            cin.clear();  // 清除错误状态
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入
            break;
        }
    }
    r->next = nullptr;

    cout << "chawan\n";
    //return L;
}

int CountList(Linklist &L) {
    int count{1};
    LNode *p = L;

    while (p->next != nullptr){
        p = p->next;
        count++;
    }
    cout << "jishuwan\n";
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


ElemType FindK2(Linklist &L, int k){
    cout << "findk2\n";
    LNode *p,*q;
    for (int i = 0; i < k; i++) {
        p = p->next;
    }
    while (p->next != nullptr){ //当p到达k时，pq同时后移
        p = p->next;
        q = q->next;
    }
    return q->data;
} //整体遍历1遍
