#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include <iostream>

#include "type.h"

using std::string;

struct Tutor {
    string ID;
    string name;
    float payRate;
    float rating;
    Date* joinDate;
    Date* terminateDate;
    Center* center;
    Subject* subject;
    Tutor();
    Tutor(string paramID, string paramName, float paramPayRate,
            float paramRating, string phone, Date* paramJoinDate,
            Date* paramTerminateDate, string paramAddress, Center* paramCenter,
            Subject* paramSubject);
    ~Tutor();
};

struct TutorArr {
    Tutor* arr;
    size_t size;
    TutorArr();
    TutorArr(size_t);
    ~TutorArr();
    void Print();
};

#endif
