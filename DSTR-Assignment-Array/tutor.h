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

/**
 * @brief Function to retrieve pointer to Tutor object with matching ID
 *
 * @param tutorV specifies the array of Tutor object to be checked
 * @param ID specifies the string to be matched
 *
 * @return nullptr if not found, else pointer to the object
 */
Tutor* getTutorByID(std::vector<Tutor> &tutorV, std::string ID);

#endif
