#pragma once
#include <vector>
#include <iostream>

#include "tutor.h"

using namespace std;
extern const std::string TUTOR_FILE;
void startMenu();
bool adminLogin();
void adminMainMenu();
void addMenu();
void sortMenu(std::vector<Tutor> &);
void searchMenu();
void deleteMenu();
