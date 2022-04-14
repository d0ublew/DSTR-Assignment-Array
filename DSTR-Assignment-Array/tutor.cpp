#include <iostream>

#include "tutor.h"

Tutor::Tutor() {
    payRate = 0;
    rating = 0;
}

Tutor::Tutor(string paramName, string paramID, float paramPayRate, float paramRating) {
    name = paramName;
    ID = paramID;
    payRate = paramPayRate;
    rating = paramRating;
}

Tutor::~Tutor() {
    /*
     * TODO: delete Date
     */
}

Tutor* CreateTutor(string name, string ID, float payRate, float rating) {
    Tutor* newTutor = new Tutor(name, ID, payRate, rating);
    return newTutor;
}

