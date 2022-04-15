#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include "tutor.h"
#include "subject.h"
#include "center.h"

size_t getLineNumber(std::string filename);
std::string* splitString(std::string, std::string);
size_t countField(std::string, std::string);

#endif
