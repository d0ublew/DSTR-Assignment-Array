#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include <string>
#include "date.h"
#include "center.h"
#include "subject.h"

struct Tutor {
    std::string ID;
    std::string name;
    float payRate;
    float rating;
    std::string phone;
    Date joinDate;
    Date terminateDate;
    Center* center;
    Subject* subject;
    size_t countRate;
    Tutor();
    ~Tutor();
};

Tutor* getTutorByID(std::vector<Tutor>& tutorV, std::string ID);

#endif
