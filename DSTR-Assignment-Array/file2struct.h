#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>
#include "tutor.h"
#include "subject.h"
#include "center.h"

extern std::string TUTOR_FILE;
extern std::string SUBJECT_FILE;
extern std::string CENTER_FILE;
extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;

std::vector<Tutor> fileToTutor(std::string filename);
std::vector<Subject> fileToSubject(std::string filename);
std::vector<Center> fileToCenter(std::string filename);
void tutorToFile(std::vector<Tutor> &tutorV, std::string filename);
std::vector<std::string> splitString(std::string str, std::string delim);
std::string float_to_str_prec(float f, int n = 2);
#endif
