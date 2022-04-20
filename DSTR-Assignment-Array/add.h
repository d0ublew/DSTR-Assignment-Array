#pragma once

#include "tutor.h"
#include <iostream>
#include <vector>

using namespace std;

extern vector<Subject> _SUBJECT;
extern vector<Center> _CENTER;

Tutor addingInterface(vector<Tutor> &arr);
void addToBack(vector<Tutor> &arr, Tutor tutor);
void addToFront(vector<Tutor> &arr, Tutor tutor);
