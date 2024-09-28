//
// Created by JJC on 2024/9/22.
//
#include <iostream>

using std::cin,std::cout;

#ifndef CHONGPAI_FUNC_H
#define CHONGPAI_FUNC_H

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList FillList(LinkList &L){
    L = new LNode;
    LNode *s,*r = L;

    int flag{};
    cin >> flag;
    while (flag != 9999){
        s = new LNode ;
        s->data = flag;
        r->next = s;
        r = s;
        cin >> flag;
    }
    r->next = nullptr;
    return L;
}

void PrintList(LinkList L){
    LNode *p = L->next;
    while (p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n-----\n" ;
}

void FindMiddle(LinkList L, LinkList &LL){
    LL = new LNode ;

    LNode *p = L->next; //走1步
    LNode *q = L->next; //走2步

    while (q->next != nullptr){
        p = p->next;
        q = q->next;
        if (q->next != nullptr) q = q->next;
    }

    LL->next = p->next;
    p->next = nullptr;
}

void Reverse(LinkList &L){
    LNode *r,*s,*t;
    r = L->next;
    if (r == nullptr) return;
    s = r->next;
    if (s == nullptr) return;
    t = s->next;

    while (t != nullptr){
        s->next = r;
        r = s;
        s = t;
        t = t->next;
    }
    s->next = r;

    L->next->next = nullptr; //后半段链表第一个有数据的指针
    L->next = s;
}

void MergeList(LinkList &L, LinkList &LL){
    LNode *cur = L->next; //前半段第一个
    LNode *p = L->next->next; //前半段第二个
    LNode *q = LL->next; //后半段

    while (p != nullptr && q != nullptr){
        cur->next = q; //cur下一个是q
        q = q->next; //q后移

        cur = cur->next; //cur 指向LL第一个结点a_n
        cur->next = p; //cur再接上p
        p = p->next; //p前移
        cur = cur->next; //cur再指向(原来L的第二个结点a2)
    }
    //在一边被清空后，另外一边可能还剩一个
    if (p != nullptr) cur->next = p;
    if (q != nullptr) cur->next = q;
}


#endif //CHONGPAI_FUNC_H
