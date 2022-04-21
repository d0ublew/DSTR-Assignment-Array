#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "tutor.h"

struct Node {
    Tutor *tutor;
    Node *next;
    Node *prev;
    Node();
    Node(Tutor &paramTutor);
    ~Node();
};

#endif
