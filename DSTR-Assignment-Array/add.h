#pragma once

#include <vector>
#include <iostream>
#include "tutor.h"


using namespace std;

extern vector<Subject> _SUBJECT;
extern vector<Center> _CENTER;

Tutor addingInterface(vector<Tutor> &arr);
void addToBack(vector<Tutor> &arr, Tutor tutor);
void addToFront(vector<Tutor> &arr, Tutor tutor);
