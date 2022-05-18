#include <iostream>
#include <stack>
#include <string>

#include "sort.h"
#include "tutor.h"

int CompareNumeric(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int CompareFloat(float a, float b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int CompareString(std::string s1, std::string s2)
{
    size_t shortest = std::min<size_t>(s1.length(), s2.length());
    for (size_t i = 0; i < shortest; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return (int)s1.length() - (int)s2.length();
}

int CompareTutorID(Tutor &t1, Tutor &t2)
{
    int result = CompareString(t1.ID, t2.ID);
    return result;
}

int CompareTutorPay(Tutor &t1, Tutor &t2)
{
    int result = CompareFloat(t1.payRate, t2.payRate);
    return result;
}

int CompareTutorRating(Tutor &t1, Tutor &t2)
{
    int result = CompareFloat(t1.rating, t2.rating);
    return result;
}

std::vector<Tutor *> sortTutor(std::vector<Tutor *> &tutorV, int (*CompareFn)(Tutor &, Tutor &), char order)
{
    /**
     * Create a binary tree where for ascending, the left sub-tree contain
     * nodes smaller than the sub-tree root and the right sub-tree contain
     * nodes bigger than or equal to the sub-tree root
     */
    BinaryTree bt = BinaryTree(tutorV, (*CompareFn), order);

    /**
     * Build a new sorted array by doing inorder traversal through the binary
     * tree
     */
    std::vector<Tutor *> sortedTutorV = bt.BTToSortedArr();
    return sortedTutorV;
}
