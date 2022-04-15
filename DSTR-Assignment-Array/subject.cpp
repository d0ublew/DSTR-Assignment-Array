#include <string>
#include <vector>

#include "subject.h"

Subject* getSubjectByID(std::vector<Subject> &subjectV, std::string ID) {
    std::vector<Subject>::iterator it;

    for (it = subjectV.begin(); it != subjectV.end(); it++) {
        Subject s = *it;
        if (s.ID == ID) {
            return &(*it);
        }
    }
    return nullptr;
}
