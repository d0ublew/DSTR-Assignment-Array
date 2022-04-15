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
    /* joinDate = nullptr; */
    /* terminateDate = nullptr; */
    center = nullptr;
    subject = nullptr;
}

Tutor::Tutor(std::string paramID, std::string paramName) {
    ID = paramID;
    name = paramName;
    payRate = 0;
    rating = 0;
    /* joinDate = nullptr; */
    /* terminateDate = nullptr; */
    center = nullptr;
    subject = nullptr;
}

Tutor::~Tutor() {
    /*
     * TODO: delete Date
     */
    /* delete joinDate; */
    /* delete terminateDate; */
}
