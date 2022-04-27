#pragma once

#include <vector>

#include "tutor.h"

using namespace std;

/**
 * @brief Function to delete tutor by ID
 *
 * @param tutorV specifies the array to be searched
 * @param ID specifies the tutor ID to be deleted
 */
void DeleteTutor(std::vector<Tutor *> &tutorV, std::string ID);

/**
 * @brief Function to delete all tutors which have been terminated for more than
 *        6 months
 *
 * @param tutorV specifies the array to be searched
 */
void DeleteTerminatedTutor(std::vector<Tutor *> &tutorV);
