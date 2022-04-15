#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>
#include "tutor.h"
#include "subject.h"
#include "center.h"

void fileToTutor(std::vector<Tutor> &tutorV, std::string filename);
void tutorToFile(std::vector<Tutor> &tutorV, std::string filename);
std::vector<std::string>* splitString(std::string str, std::string delim);
#endif
