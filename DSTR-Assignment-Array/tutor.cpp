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
    countRate = 0;
    joinDate = Date("-");
    terminateDate = Date("-");
    center = nullptr;
    subject = nullptr;
}

Tutor::~Tutor() {}

Tutor getTutorByID(std::vector<Tutor> &tutorV, std::string ID) {
    Tutor query;
    query.ID = ID;
    std::vector<Tutor> result = searchTutor(tutorV, query, &CompareTutorID);
    query.ID = "";
    if (result.size() == 0) return query;

    return result.at(0);
}
