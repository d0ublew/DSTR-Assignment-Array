#pragma once

#include <string>
#include <vector>

#include "tutor.h"

std::vector<Tutor> searchByID(std::vector<Tutor> &, std::string);
std::vector<Tutor> searchByRating(std::vector<Tutor> &, float);

int binarySearch(std::vector<Tutor> &v, Tutor x,
                 int (*CompareFn)(Tutor &, Tutor &), int offset = 0);
std::vector<Tutor> searchTutor(std::vector<Tutor> &v, Tutor t,
                               int (*CompareFn)(Tutor &, Tutor &));
std::vector<Tutor> slice(std::vector<Tutor> &, int, int);
