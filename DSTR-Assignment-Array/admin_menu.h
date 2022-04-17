#pragma once
#include <vector>
#include <iostream>

#include "tutor.h"

using namespace std;
extern const std::string TUTOR_FILE;
void startMenu(std::vector<Tutor> &tutorV);
bool adminLogin();
void adminMainMenu(std::vector<Tutor> &tutorV);
void addMenu(std::vector<Tutor> &tutorV);
void sortMenu(std::vector<Tutor> &);
void searchMenu(std::vector<Tutor> &tutorV);
void deleteMenu(std::vector<Tutor> &tutorV);
void clearScreen();
