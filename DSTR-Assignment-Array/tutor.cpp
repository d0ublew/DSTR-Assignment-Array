#include <iostream>
#include <string>
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

Tutor* getTutorByID(std::vector<Tutor>& tutorV, std::string ID) {
    std::vector<Tutor>::iterator it;

    for (it = tutorV.begin(); it != tutorV.end(); it++) {
        Tutor s = *it;
        if (s.ID == ID) {
            return &(*it);
        }
    }
    return nullptr;
}
