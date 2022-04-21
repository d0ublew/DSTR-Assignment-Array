#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include "node.h"

struct BinaryTree {
    Node *root;
    BinaryTree();
    ~BinaryTree();
    BinaryTree(std::vector<Tutor> &v, int (*CompareFn)(Tutor &, Tutor &),
               char order);
    std::vector<Tutor> BTToSortedArr();
};

#endif
