#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <string>

#include "tutor.h"

int CompareNumeric(int, int);

int CompareFloat(float, float);

int CompareString(std::string, std::string);

int CompareTutorID(Tutor &, Tutor &);

int CompareTutorPay(Tutor &, Tutor &);

int CompareTutorRating(Tutor &, Tutor &);

std::vector<Tutor> sortTutor(std::vector<Tutor> &, int (*)(Tutor &, Tutor &),
        char order);

void SortMenu();

struct Node {
    Tutor* tutor;
    Node* next;
    Node* prev;
    Node();
    Node(Tutor &paramTutor);
    ~Node();
};

struct BinaryTree {
    Node* root;
    BinaryTree();
    ~BinaryTree();
    BinaryTree(std::vector<Tutor> &v, int (*CompareFn)(Tutor &, Tutor &), char order);
    std::vector<Tutor> BTToSortedArr();
};


#endif
