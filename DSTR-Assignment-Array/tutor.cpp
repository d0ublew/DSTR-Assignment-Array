#include <iostream>

#include "tutor.h"
#include "date.h"
#include "center.h"
#include "subject.h"

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
    delete joinDate;
    delete terminateDate;
}

TutorArr::TutorArr() {
    arr = nullptr;
    size = 0;
}

TutorArr::TutorArr(size_t paramSize) {
    size = paramSize;
    arr = new Tutor[size];
}

TutorArr::~TutorArr() {
    delete[] arr;
}

void TutorArr::Print() {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i].ID << '\n';
        std::cout << arr[i].name << '\n';
        std::cout << arr[i].payRate << '\n';
        std::cout << arr[i].rating << '\n';
        std::cout << arr[i].phone << '\n';
        std::cout << arr[i].joinDate->ToString() << '\n';
        std::cout << arr[i].terminateDate->ToString() << '\n';
        std::cout << arr[i].center->ID << '\n';
        std::cout << arr[i].center->name << '\n';
        std::cout << arr[i].subject->ID << '\n';
        std::cout << arr[i].subject->name << '\n';
        puts("");
    }
}
