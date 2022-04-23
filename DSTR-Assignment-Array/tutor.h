#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include "center.h"
#include "date.h"
#include "subject.h"
#include <string>

struct Tutor
{
    std::string ID;
    std::string name;
    float payRate;
    float rating;
    std::string phone;
    std::string address;
    Date joinDate;
    Date terminateDate;
    Center *center;
    Subject *subject;
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
 * @return tutor object with empty ID if not found, else matched tutor object
 */
Tutor *getTutorByID(std::vector<Tutor *> &tutorV, std::string ID);

void deallocateTutor(std::vector<Tutor *> &tutorV);

#endif
