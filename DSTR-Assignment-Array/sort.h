#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <string>

#include "binary_tree.h"
#include "tutor.h"

/**
 * @brief Compare two integers
 *
 * @param compared specifies the compared integer
 * @param based specifies the based integer
 *
 * @return 1 if larger, -1 if smaller, 0 if equal
 */
int CompareNumeric(int compared, int based);

/**
 * @brief Compare two floats
 *
 * @param compared specifies the compared float
 * @param based specifies the based float
 *
 * @return 1 if larger, -1 if smaller, 0 if equal
 */
int CompareFloat(float compared, float based);

/**
 * @brief Compare two strings lexicographically
 *
 * @param compared specifies the compared string
 * @param based specifies the based string
 *
 * @return negative integer if smaller, positive if bigger, zero if equal
 */
int CompareString(std::string compared, std::string based);

/**
 * @brief Compare two Tutor ID lexicographically
 *
 * @param compared specifies the compared Tutor
 * @param based specifies the based Tutor
 *
 * @return negative integer if smaller, positive if bigger, zero if equal
 */
int CompareTutorID(Tutor &compared, Tutor &based);

/**
 * @brief Compare two Tutor pay rate
 *
 * @param compared specifies the compared Tutor
 * @param based specifies the based Tutor
 *
 * @return -1 if smaller, 1 if larger, 0 if equal
 */
int CompareTutorPay(Tutor &, Tutor &);

/**
 * @brief Compare two Tutor rating
 *
 * @param compared specifies the compared Tutor
 * @param based specifies the based Tutor
 *
 * @return -1 if smaller, 1 if larger, 0 if equal
 */
int CompareTutorRating(Tutor &, Tutor &);

/**
 * @brief Sort tutor array with specified order and compare function
 *
 * @param tutorV specifies the array to be sorted
 * @param CompareFn specifies the compare function to sort the array
 * @param order specifies the sorting order, 'a' for ascending, 'd' for descending
 *
 * @return a sorted array
 */
std::vector<Tutor *> sortTutor(std::vector<Tutor *> &tutorV, int (*CompareFn)(Tutor &, Tutor &), char order);

#endif
