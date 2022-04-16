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
    countRate = 0;
    joinDate = Date("-");
    terminateDate = Date("-");
    center = nullptr;
    subject = nullptr;
}

Tutor::~Tutor() {
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
