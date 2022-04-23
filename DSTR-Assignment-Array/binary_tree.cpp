#include <iostream>
#include <stack>

#include "binary_tree.h"
#include "my_stack.h"

BinaryTree::BinaryTree() { root = nullptr; }

BinaryTree::~BinaryTree() {}

BinaryTree::BinaryTree(std::vector<Tutor *> &v,
                       int (*CompareFn)(Tutor &, Tutor &), char order) {
    root = nullptr;
    if (v.size() == 0) return;

    std::vector<Tutor *>::iterator it;
    root = new Node(v.at(0));
    root->next = nullptr;
    root->prev = nullptr;

    for (it = next(v.begin()); it != v.end(); it++) {
        Node *treeNodePtr = root;
        int result;
        Node *treeNodePtrParent = nullptr;
        while (treeNodePtr != nullptr) {
            treeNodePtrParent = treeNodePtr;
            Tutor *vData = *it;
            Tutor *treeData = treeNodePtr->tutor;
            result = (*CompareFn)(*vData, *treeData);
            if (order == 'a') {
                if (result > 0) {
                    treeNodePtr = treeNodePtr->next;
                } else {
                    treeNodePtr = treeNodePtr->prev;
                }
            } else {
                if (result > 0)
                    treeNodePtr = treeNodePtr->prev;
                else
                    treeNodePtr = treeNodePtr->next;
            }
        }

        if (order == 'a') {
            if (result > 0) {
                treeNodePtrParent->next = new Node(*it);
                treeNodePtr = treeNodePtrParent->next;
            } else {
                treeNodePtrParent->prev = new Node(*it);
                treeNodePtr = treeNodePtrParent->prev;
            }
        } else {
            if (result > 0) {
                treeNodePtrParent->prev = new Node(*it);
                treeNodePtr = treeNodePtrParent->prev;
            } else {
                treeNodePtrParent->next = new Node(*it);
                treeNodePtr = treeNodePtrParent->next;
            }
        }
        treeNodePtr->next = nullptr;
        treeNodePtr->prev = nullptr;
    }
}

std::vector<Tutor *> BinaryTree::BTToSortedArr() {
    /**
     * Binary tree iterative inorder traversal with the help of stack to keep
     * track of traversed node
     */
    std::vector<Tutor *> sortedTutorV;
    MyStack nodeStack;
    Node *treeNodePtr = root;
    while (!nodeStack.Empty() || treeNodePtr != nullptr) {
        if (treeNodePtr != nullptr) {
            nodeStack.Push(treeNodePtr);
            treeNodePtr = treeNodePtr->prev;
        } else {
            treeNodePtr = nodeStack.Top();
            sortedTutorV.push_back(treeNodePtr->tutor);
            nodeStack.Pop();
            /**
             * Save the node address which data has been added to the array to
             * be deallocated
             */
            Node *tmp = treeNodePtr;
            treeNodePtr = treeNodePtr->next;
            delete tmp;
        }
    }
    return sortedTutorV;
}
