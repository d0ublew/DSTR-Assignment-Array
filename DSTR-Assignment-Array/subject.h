#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include <string>
#include <vector>

struct Subject {
    std::string name;
    std::string ID;
};

/**
 * @brief Function to retrieve pointer to Subject object with matching ID
 *
 * @param subjectV specifies the array of Subject object to be checked
 * @param ID specifies the string to be matched
 *
 * @return nullptr if not found, else pointer to the object
 */
Subject* getSubjectByID(std::vector<Subject> &subjectV, std::string);

#endif
