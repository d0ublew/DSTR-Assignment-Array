#pragma once

#include <iostream>
#include <vector>

#include "tutor.h"

extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;

Tutor *addingInterface(std::vector<Tutor *> &arr);
void addToBack(std::vector<Tutor *> &arr, Tutor *tutor);
void addToFront(std::vector<Tutor *> &arr, Tutor *tutor);
