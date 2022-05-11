#pragma once

#include <string>
#include <vector>

#include "tutor.h"

/**
 * @brief perform binary search on sorted array and returns index
 *
 * @param v specifies the sorted array to be searched
 * @param x specifies the tutor to be matched
 * @param CompareFn specifies the function to compare two tutors
 *
 * @return -1 if not found, otherwise returns the matching index
 */
int binarySearch(std::vector<Tutor *> &v, Tutor x, int (*CompareFn)(Tutor &, Tutor &));

/**
 * @brief search tutor
 *
 * @param v specifies the array to be searched
 * @param t specifies the tutor to be matched
 * @param CompareFn specifies the function to compare two tutors
 *
 * @return tutor array with matching results
 */
std::vector<Tutor *> searchTutor(std::vector<Tutor *> &v, Tutor t, int (*CompareFn)(Tutor &, Tutor &));

/**
 * @brief slice vector given starting index and ending index [start, end]
 *
 * @param v specifies the vector be sliced
 * @param start specifies the starting index
 * @param end specifies the ending index
 *
 * @return sliced vector
 */
std::vector<Tutor *> slice(std::vector<Tutor *> &v, int start, int end);
