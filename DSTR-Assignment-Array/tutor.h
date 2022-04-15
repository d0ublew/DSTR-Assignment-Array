#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include <string>
#include "type.h"

struct Tutor {
    std::string ID;
    std::string name;
    float payRate;
    float rating;
    std::string phone;
    Date* joinDate;
    Date* terminateDate;
    Center* center;
    Subject* subject;
    Tutor();
    Tutor(std::string paramID, std::string paramName);
    ~Tutor();
};

#endif
