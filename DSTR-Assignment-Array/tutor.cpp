#include <iostream>
#include <string>

#include "center.h"
#include "date.h"
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

/**
 * @brief Function to retrieve Tutor pointer with matched ID
 *
 * @param tutorV specify the vector to be looked at
 * @param ID specify the inquired ID
 *
 * @return nullptr if no match ID, otherwise return the pointer
 */
Tutor *getTutorByID(std::vector<Tutor> &tutorV, std::string ID) {
    std::vector<Tutor>::iterator it;

    for (it = tutorV.begin(); it != tutorV.end(); it++) {
        Tutor s = *it;
        if (s.ID == ID) {
            return &(*it);
        }
    }
    return nullptr;
}
