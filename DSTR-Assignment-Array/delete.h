#pragma once

#include <vector>

#include "tutor.h"

using namespace std;

void DeleteTutor(std::vector<Tutor *> &subTutorV, std::string);
void DeleteTerminatedTutor(std::vector<Tutor *> &tutorV);
