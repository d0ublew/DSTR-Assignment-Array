#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>
#include "tutor.h"
#include "subject.h"
#include "center.h"

std::vector<Tutor> fileToTutor(std::string filename);
std::vector<Subject> fileToSubject(std::string filename);
std::vector<Center> fileToCenter(std::string filename);
std::vector<std::string> splitString(std::string str, std::string delim);

#endif
