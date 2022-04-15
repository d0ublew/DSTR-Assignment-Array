#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include <string>
#include <vector>

struct Subject {
    std::string name;
    std::string ID;
};

Subject* getSubjectByID(std::vector<Subject> &, std::string);

#endif
