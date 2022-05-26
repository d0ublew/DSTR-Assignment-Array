#pragma once
#include "center.h"
#include "subject.h"
#include "tutor.h"
#include <iostream>
#include <vector>

extern std::vector<Subject> _SUBJECT;
extern std::vector<Center> _CENTER;
void DisplayTutor(std::vector<Tutor *> &arr, bool isAdmin = true);
void DisplaySubject();
void DisplayCenter();
void DisplayOneTutor(Tutor *, bool isAdmin = true);
void SubDisplay(std::vector<Tutor *> &, size_t start, size_t end, bool isAdmin = true);
void clearScreen();
