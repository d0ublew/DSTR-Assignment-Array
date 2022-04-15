#include <iostream>

#include "date.h"
#include "tutor.h"
#include "file2struct.h"
#include "subject.h"

SubjectArr* SUBJECT_ARR = fileToSubject("./data/subject.txt");
CenterArr* CENTER_ARR = fileToCenter("./data/center.txt");
TutorArr* TUTOR_ARR = fileToTutor("./data/tutor.txt");

int main() {
    TUTOR_ARR->Print();
    SUBJECT_ARR->Print();
    CENTER_ARR->Print();
    size_t size = TUTOR_ARR->size;
    TutorArr* copy = new TutorArr(size+1);
    Tutor* c = copy->arr;
    Tutor* a = TUTOR_ARR->arr;
    for (size_t i = 0; i < size; i++) {
        c[i] = *new Tutor(a[i]);
        c[i].joinDate = new Date(*a[i].joinDate);
        c[i].terminateDate = new Date(*a[i].terminateDate);
    }
    delete TUTOR_ARR;
    TUTOR_ARR = copy;
    Tutor* arr = TUTOR_ARR->arr;
    size = TUTOR_ARR->size;
    size--;
    arr[size].ID = "T04";
    arr[size].name = "Four";
    arr[size].payRate = std::stof("4.20");
    arr[size].rating = std::stof("4.3");
    arr[size].phone = "akdfj";
    arr[size].joinDate = new Date("1/2/2022");
    arr[size].terminateDate = new Date("-");
    arr[size].center = CENTER_ARR->getCenterByID("C02");
    arr[size].subject = SUBJECT_ARR->getSubjectByID("S03");
    TUTOR_ARR->Print();
    delete TUTOR_ARR;
    delete SUBJECT_ARR;
    delete CENTER_ARR;
    return 0;
}
