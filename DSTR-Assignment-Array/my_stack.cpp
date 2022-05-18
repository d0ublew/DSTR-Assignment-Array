#include <iostream>

#include "my_stack.h"
#include "node.h"

StackNode::StackNode()
{
    data = nullptr;
    next = nullptr;
}

StackNode::StackNode(Node *paramData)
{
    data = paramData;
    next = nullptr;
}

StackNode::~StackNode()
{
}

StackList::StackList()
{
    head = nullptr;
}

StackList::~StackList()
{
    while (head != nullptr)
    {
        DeleteBeginning();
    }
}

void StackList::InsertBeginning(Node *data)
{
    StackNode *newStackNode = new StackNode(data);
    if (head == nullptr)
    {
        head = newStackNode;
        return;
    }
    newStackNode->next = head;
    head = newStackNode;
}

void StackList::DeleteBeginning()
{
    if (head == nullptr)
        return;

    StackNode *ptr = head;
    if (head->next != nullptr)
    {
        head = head->next;
    }
    else
    {
        head = nullptr;
    }
    delete ptr;
}

MyStack::MyStack()
{
}

MyStack::~MyStack()
{
}

bool MyStack::Empty()
{
    return (ll.head == nullptr) ? true : false;
}

void MyStack::Push(Node *data)
{
    ll.InsertBeginning(data);
}

void MyStack::Pop()
{
    ll.DeleteBeginning();
}

Node *MyStack::Top()
{
    if (Empty())
        return nullptr;
    return ll.head->data;
}
