#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include "node.h"

struct BinaryTree
{
    Node *root;
    BinaryTree();
    ~BinaryTree();
    /**
     * @brief construct a binary tree where if ascending, the left sub-tree
     *        contain nodes smaller than the sub-tree root and the right
     *        sub-tree contain nodes bigger than or equal to the sub-tree root
     *
     * @param v specifies the array to be used to construct the binary tree
     * @param CompareFn specifies the function pointer to do comparison
     * @param order specifies the order of sorting
     */
    BinaryTree(std::vector<Tutor *> &v, int (*CompareFn)(Tutor &, Tutor &), char order);
    std::vector<Tutor *> BTToSortedArr();
};

#endif
