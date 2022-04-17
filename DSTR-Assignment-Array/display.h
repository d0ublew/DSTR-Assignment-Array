#pragma once
#include <vector>
#include "tutor.h"
#include <iostream>
#include "center.h"
#include "subject.h"

using namespace std;
extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;
void DisplayTutor(vector<Tutor> &arr, bool isAdmin = true);
void DisplaySubject();
void DisplayCenter();
