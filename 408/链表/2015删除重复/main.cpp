#include <iostream>

using std::cin,std::cout,std::endl;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

int count(LinkList &L){
    int count{0};
    LNode *p = L;
    while (p->next != nullptr){
        p = p -> next;
        count++;
    }
    return count;
}

LinkList FillList(LinkList &L) {
    L = new LNode;
    LNode *s,*r = L;
    int flag = 0;

    cin >> flag;
    while (flag != 9999){
        s = new LNode ;
        s->data = flag;
        r->next = s;
        r = s;

        cin >> flag;
    }
    r->next = nullptr;
    cout << "输入完成\n";
    return L;
}

void PrintList(LinkList L) {
    LNode *p = L->next; // 跳过头节点
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 释放链表的内存
void FreeList(LinkList L) {
    LNode *p;
    while (L != nullptr) {
        p = L;
        L = L->next;
        delete p;
    }
}

int abs1(int a){
    if (a >= 0) return a;
    else return -a;
}

LinkList UpdateList(LinkList &L, int n){
    bool *hash = new bool[n]();

    LNode *p = L;
    LNode *q = nullptr;

    while (p->next != nullptr) {
        int num = abs1(p->next->data);
        if (!hash[num]) {
            hash[abs1(num)] = true;
            p = p->next;
        } else {
            q = p->next;
            //p->data = p->next->data;
            p->next = q->next;
            delete q;
        }
    }

    delete[] hash;
    return L;
}

int main() {
    int n{50};
    LinkList L = nullptr;
    L = FillList(L);

    cout << "开始更新数组\n";
    UpdateList(L,n);

    PrintList(L);

    FreeList(L);
}
