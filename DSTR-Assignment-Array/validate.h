#pragma once


#include <vector>
#include <iostream>
#include "tutor.h"
#include "subject.h"
#include "center.h"

using namespace std;
extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;


bool isTutorIDExisted(vector<Tutor> &arr, string ID);
bool isTutorIDFormatCorrect(string ID);
bool isCenterExisted(Center* c);
bool isSubjectExisted(Subject* s);
bool isDateFormatValid(string date);
bool isPhoneFormatValid(string phone);
bool isPayRateRangeValid(float payRate);
bool isRatingRateRangeValid(float rate);
int checkIntInput(string sentence);

