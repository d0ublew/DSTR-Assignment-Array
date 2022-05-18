#include <iostream>
#include <stack>

#include "binary_tree.h"
#include "my_stack.h"

BinaryTree::BinaryTree() { root = nullptr; }

BinaryTree::~BinaryTree() {}

BinaryTree::BinaryTree(std::vector<Tutor *> &v,
                       int (*CompareFn)(Tutor &, Tutor &), char order) {
  root = nullptr;
  if (v.size() == 0)
    return;

  std::vector<Tutor *>::iterator it;
  root = new Node(v.at(0));

  for (it = next(v.begin()); it != v.end(); it++) {
    Node *treeNodePtr = root;

    // Traverse until end of tree
    while (treeNodePtr != nullptr) {
      Tutor *vData = *it;
      Tutor *treeData = treeNodePtr->tutor;
      int result = (*CompareFn)(*vData, *treeData);
      if (order == 'a') {
        if (result > 0) {
          // reach end of tree
          if (treeNodePtr->next == nullptr) {
            treeNodePtr->next = new Node(*it);
            break;
          }
          treeNodePtr = treeNodePtr->next;
        } else {
          // reach end of tree
          if (treeNodePtr->prev == nullptr) {
            treeNodePtr->prev = new Node(*it);
            break;
          }
          treeNodePtr = treeNodePtr->prev;
        }
      } else {
        if (result > 0) {
          // reach end of tree
          if (treeNodePtr->prev == nullptr) {
            treeNodePtr->prev = new Node(*it);
            break;
          }
          treeNodePtr = treeNodePtr->prev;
        } else {
          // reach end of tree
          if (treeNodePtr->next == nullptr) {
            treeNodePtr->next = new Node(*it);
            break;
          }
          treeNodePtr = treeNodePtr->next;
        }
      }
    }
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
      /**
       * Traverse left sub-tree while keeping track of traversed node
       */
      nodeStack.Push(treeNodePtr);
      treeNodePtr = treeNodePtr->prev;
    } else {
      /**
       * Reached end of left sub-tree, go back to parent node which can
       * be retrieved from stack, append the node to new sorted array,
       * traverse the right sub-tree
       */
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
