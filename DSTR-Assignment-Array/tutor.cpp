#include <iostream>

#include "tutor.h"

Tutor::Tutor() {
    ID = "";
    name = "";
    payRate = 0;
    rating = 0;
    joinDate = nullptr;
    terminateDate = nullptr;
    center = nullptr;
    subject = nullptr;
}

Tutor::~Tutor() {
    /*
     * TODO: delete Date
     */
}

TutorArr::TutorArr() {
    arr = nullptr;
    size = 0;
}

TutorArr::TutorArr(size_t paramSize) {
    arr = new Tutor[paramSize];
    size = paramSize;
    puts("called");
}

TutorArr::~TutorArr() {
    delete[] arr;
}

void TutorArr::Print() {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i].ID << ' ' << arr[i].name << '\n';
    }
}
