#include <iostream>
#include <string>
#include <stack>

#include "sort.h"
#include "tutor.h"

int CompareNumeric(int a, int b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int CompareFloat(float a, float b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int CompareString(std::string s1, std::string s2) {
    size_t shortest = std::min<size_t>(s1.length(), s2.length());
    for (size_t i = 0; i < shortest; i++) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
    return (int) s1.length() - (int) s2.length();
}

int CompareTutorID(Tutor &t1, Tutor &t2) {
    int result = CompareString(t1.ID, t2.ID);
    return result;
}

int CompareTutorPay(Tutor &t1, Tutor &t2) {
    int result = CompareFloat(t1.payRate, t2.payRate);
    return result;
}

int CompareTutorRating(Tutor &t1, Tutor &t2) {
    int result = CompareFloat(t1.rating, t2.rating);
    return result;
}

std::vector<Tutor> sortTutor(std::vector<Tutor> &tutorV,
        int (*CompareFn)(Tutor &, Tutor &), char order) {
    BinaryTree* bt = new BinaryTree(tutorV, (*CompareFn), order);
    std::vector<Tutor> sortedTutorV = bt->BTToSortedArr();
    delete bt;
    return sortedTutorV;
}

Node::Node() {
    next = nullptr;
    prev = nullptr;
}

Node::Node(Tutor &paramTutor) {
    tutor = &paramTutor;
    next = nullptr;
    prev = nullptr;
}

Node::~Node() {

}

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {

}

BinaryTree::BinaryTree(std::vector<Tutor> &v,
        int (*CompareFn)(Tutor &, Tutor &), char order) {
    root = nullptr;
    if (v.size() == 0) return;

    std::vector<Tutor>::iterator it;
    root = new Node(v.at(0));
    root->next = nullptr;
    root->prev = nullptr;

    for (it = next(v.begin()); it != v.end(); it++) {
        Node* treeNodePtr = root;
        int result;
        Node* treeNodePtrParent = nullptr;
        while (treeNodePtr != nullptr) {
            treeNodePtrParent = treeNodePtr;
            Tutor vData = *it;
            Tutor treeData = *(treeNodePtr->tutor);
            result = (*CompareFn)(vData, treeData);
            if (order == 'a') {
                if (result > 0) {
                    treeNodePtr = treeNodePtr->next;
                }
                else {
                    treeNodePtr = treeNodePtr->prev;
                }
            }
            else {
                if (result > 0) treeNodePtr = treeNodePtr->prev;
                else treeNodePtr = treeNodePtr->next;
            }
        }

        Tutor t = *it;
        if (order == 'a') {
            if (result > 0) {
                treeNodePtrParent->next = new Node(*it);
                treeNodePtrParent->next->next = nullptr;
                treeNodePtrParent->next->prev = nullptr;
            }
            else {
                treeNodePtrParent->prev = new Node(*it);
                treeNodePtrParent->prev->next = nullptr;
                treeNodePtrParent->prev->prev = nullptr;
            }
        }
        else {
            if (result > 0) {
                treeNodePtrParent->prev = new Node(*it);
                treeNodePtrParent->prev->next = nullptr;
                treeNodePtrParent->prev->prev = nullptr;
            }
            else {
                treeNodePtrParent->next = new Node(*it);
                treeNodePtrParent->next->next = nullptr;
                treeNodePtrParent->next->prev = nullptr;
            }
        }
    }

}

std::vector<Tutor> BinaryTree::BTToSortedArr() {
    std::vector<Tutor> sortedTutorV;
    std::stack<Node*> nodeStack;
    Node* treeNodePtr = root;
    while (!nodeStack.empty() || treeNodePtr != nullptr) {
        if (treeNodePtr != nullptr) {
            nodeStack.push(treeNodePtr);
            treeNodePtr = treeNodePtr->prev;
        }
        else {
            treeNodePtr = nodeStack.top();
            sortedTutorV.push_back(*(treeNodePtr->tutor));
            nodeStack.pop();
            Node* tmp = treeNodePtr;
            treeNodePtr = treeNodePtr->next;
            delete tmp;
        }
    }
    return sortedTutorV;
}
