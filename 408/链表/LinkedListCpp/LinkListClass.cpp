//
// Created by JJC on 2024/9/22.
//

#include "LinkListClass.h"

LinkList::LinkList()  {
    head = new Node(int());
    head->next = nullptr;
}

LinkList::~LinkList() {
    Node *cur = head;
    if (cur != nullptr) {
        Node *temp = cur;
        cur = cur->next;
        delete temp;
    }
}

void LinkList::Insert(int val)  {
    Node *node = new Node(val);
    Node *cur = head;
    while (cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = node;
}

void LinkList::FillList()  {
    int val;
    cout << "请输入非9999的整数\n";
    cin >> val;

    while (val != 9999) {
        Insert(val);
        cin >> val;
    }
    cout << "输入完成\n" ;
}

void LinkList::PrintList() const  {
    Node *p = head->next;

    while (p != nullptr){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << "\n-------\n";
}
