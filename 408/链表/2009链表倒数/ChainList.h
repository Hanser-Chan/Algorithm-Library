//
// Created by JJC on 2024/9/21.
//
#include <iostream>

using std::cin,std::cout;

#ifndef CHAINLIST_CHAINLIST_H
#define CHAINLIST_CHAINLIST_H

//这里给出两种定义链表的方法

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode , *Linklist;

//函数部分
bool InitList(Linklist &L) ;

void FillList(Linklist &L);

int CountList(Linklist &L);

ElemType FindK1(Linklist &L, int k);

ElemType FindK2(Linklist &L, int k);


template <typename T>
class LLNode{
public:
    T data;
    LLNode* next;

    LLNode(T d, LLNode *n = nullptr) : data(d),next(n) {}

    void FillList(LLNode* &L){
        T flag;
        L = new LLNode(0);

        LLNode *r = L;

        cin >> flag;
        while (flag != 9999){
            LLNode* s = new LLNode(flag);
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

        cout << "classNodeOK\n";
    }

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
};


#endif //CHAINLIST_CHAINLIST_H
