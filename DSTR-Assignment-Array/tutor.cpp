#include <iostream>
#include <string>

#include "center.h"
#include "date.h"
#include "search.h"
#include "sort.h"
#include "subject.h"
#include "tutor.h"

Tutor::Tutor() {
    ID = "";
    name = "";
    payRate = 0;
    rating = 0;
    phone = "";
    address = "";
    joinDate = Date("-");
    terminateDate = Date("-");
    center = nullptr;
    subject = nullptr;
    countRate = 0;
}

Tutor::~Tutor() {}

Tutor *getTutorByID(std::vector<Tutor *> &tutorV, std::string ID) {
    Tutor query;
    query.ID = ID;
    std::vector<Tutor *> result = searchTutor(tutorV, query, &CompareTutorID);
    if (result.size() == 0) return nullptr;

    return result.at(0);
}

void deallocateTutor(std::vector<Tutor *> &tutorV) {
    std::vector<Tutor *>::iterator it;

    for (it = tutorV.begin(); it != tutorV.end(); it++) {
        Tutor *ptr = *it;
        delete ptr;
    }
}
