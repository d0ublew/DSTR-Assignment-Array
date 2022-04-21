#include "node.h"
#include "tutor.h"

Node::Node() {
    next = nullptr;
    prev = nullptr;
}

Node::Node(Tutor &paramTutor) {
    tutor = &paramTutor;
    next = nullptr;
    prev = nullptr;
}

Node::~Node() {}
