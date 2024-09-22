//
// Created by JJC on 2024/9/22.
//
#include <iostream>
using std::cin,std::cout;
#ifndef LINKEDLIST_LINKLISTCLASS_H
#define LINKEDLIST_LINKLISTCLASS_H

class Node{
public:
    int data;
    Node *next;

    explicit Node(int val) : data(val) , next(nullptr) {}
};

class LinkList{
public:
    Node *head;

    explicit LinkList();

    virtual ~LinkList();

    void Insert(int val) ;

    void FillList() ;

    void PrintList() const ;
};


#endif //LINKEDLIST_LINKLISTCLASS_H
