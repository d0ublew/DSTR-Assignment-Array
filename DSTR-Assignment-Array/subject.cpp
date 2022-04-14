#include <iostream>

#include "subject.h"

SubjectArr::SubjectArr() {
    arr = nullptr;
    size = 0;
}

SubjectArr::SubjectArr(size_t paramSize) {
    arr = new Subject[paramSize];
    size = paramSize;
}

SubjectArr::~SubjectArr() {
    delete[] arr;
}

Subject* SubjectArr::getSubjectByID(std::string ID) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i].ID == ID) {
            return &arr[i];
        }
    }
    return nullptr;
}

void SubjectArr::Print() {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i].ID << ' ' << arr[i].name << '\n';
    }
}
