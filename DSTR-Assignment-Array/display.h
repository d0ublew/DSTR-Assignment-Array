#pragma once
#include "center.h"
#include "subject.h"
#include "tutor.h"
#include <iostream>
#include <vector>

using namespace std;
extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;
void DisplayTutor(vector<Tutor *> &arr, bool isAdmin = true);
void DisplaySubject();
void DisplayCenter();
