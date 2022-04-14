#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include <string>

struct Subject {
    std::string name;
    std::string ID;
};

struct SubjectArr {
    Subject* arr;
    size_t size;
    SubjectArr();
    SubjectArr(size_t);
    ~SubjectArr();
    void Print();
    Subject* getSubjectByID(std::string);
};

#endif
