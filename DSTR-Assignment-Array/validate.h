#pragma once

#include "admin.h"
#include "center.h"
#include "student.h"
#include "subject.h"
#include "tutor.h"
#include <iostream>
#include <vector>

extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;

/**
 * @brief Verify if supplied Tutor ID exists or not
 *
 * @param arr specifies the object of Tutors to be checked
 * @param ID specifies the ID to be verified
 *
 * @return true if exists, else false
 */
bool isTutorIDExisted(std::vector<Tutor> &arr, std::string ID);

/**
 * @brief Verify if supplied Tutor ID matches the required format
 *
 * @param ID specifies the ID to be verified
 *
 * @return true if matches, else false
 */
bool isTutorIDFormatCorrect(std::string ID);

/**
 * @brief Verify if supplied pointer to Center object exists or not
 *
 * @param c specifies pointer to the Center object to be verified
 *
 * @return true if exists, else false
 */
bool isCenterExisted(Center *c);

/**
 * @brief Verify if supplied pointer Subject object exists or not
 *
 * @param s specifies pointer to the Subject object to be verified
 *
 * @return true if exists, else false
 */
bool isSubjectExisted(Subject *s);

bool isAdminUsernameExisted(vector<Admin> &arr, string username);
bool isStudentUsernameExisted(vector<Student> &arr, string username);

/**
 * @brief Verify if supplied date string valids or not
 *
 * @param date specifies the date string to be verified
 *
 * @return true if valids, else false
 */
bool isDateValid(std::string date);

/**
 * @brief Verify if supplied phone string valids or not
 *
 * @param phone specifies the phone string to be verified
 *
 * @return true if valids, else false
 */
bool isPhoneFormatValid(std::string phone);

/**
 * @brief Verify if supplied pay rate falls in between 40 and 80
 *
 * @param payRate specifies the value to be verified
 *
 * @return true if valids, else false
 */
bool isPayRateRangeValid(float payRate);

/**
 * @brief Verify if supplied rating falls between 1 and 5
 *
 * @param rate specifies the value to be verified
 *
 * @return true if valids, else false
 */
bool isRatingRateRangeValid(float rate);

/**
 * @brief Function to only accept integer input
 *
 * @param sentence specifies the input prompt
 *
 * @return integer input
 */
int checkIntInput(std::string sentence);

/**
 * @brief Function to only accept float input
 *
 * @param sentence specifies the input prompt
 *
 * @return float input
 */
float checkFloatInput(std::string sentence);

/**
 * @brief To clear input buffer after scanning numeric input
 */
void clearInputBuffer();

/**
 * @brief Verify if supplied choice is between 0 and the parameter `end`
 *
 * @param choice specifies the value to be verified
 * @param end specifies the end boundary
 *
 * @return true if valids, else false
 */
bool isChoiceInMenuRange(int choice, int end);

/**
 * @brief Verify if supplied year is a leap year
 *
 * @param year specifies the value to be verified
 *
 * @return true if leap year, else false
 */
bool isLeap(int year);

/**
 * @brief Use to ask user to press enter after giving invalid input
 */
void Enter();
bool isSpaceExisted(string s);
