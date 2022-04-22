#ifndef MY_STACK_H_INCLUDED
#define MY_STACK_H_INCLUDED

#include "node.h"
#include <iostream>

struct StackNode {
    Node *data;
    StackNode *next;
    StackNode();
    StackNode(Node *paramData);
    ~StackNode();
};

struct StackList {
    StackNode *head;
    StackList();
    ~StackList();
    void InsertBeginning(Node *data);
    void DeleteBeginning();
};

struct MyStack {
    StackList ll;
    MyStack();
    ~MyStack();
    void Push(Node *data);
    Node *Top();
    void Pop();
    bool Empty();
};

#endif
