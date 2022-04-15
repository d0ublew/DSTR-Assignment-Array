#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>
#include "tutor.h"
#include "subject.h"
#include "center.h"

void fileToTutor(std::vector<Tutor> &tutorV, std::vector<Subject> &subjectV,
        std::vector<Center> &centerV, std::string filename);
void fileToSubject(std::vector<Subject> &subjectV, std::string filename);
void fileToCenter(std::vector<Center> &centerV, std::string filename);
void splitString(std::vector<std::string> &data, std::string str, std::string delim);
#endif
