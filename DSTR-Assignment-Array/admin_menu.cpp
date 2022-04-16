#include <iostream>
#include <string>
#include "validate.h"

using namespace std;

int startMenu();
int adminMainMenu();
int addMenu();
int sortMenu();
int searchMenu();
int deleteMenu();



int startMenu()
{
	cout << "Welcome to eXcel Tuition Centre" << endl;
	cout << "Who are you?" << endl;
	cout << "1) Admin" << endl;
	cout << "2) Student" << endl;
	string sentence = "Enter your choice: ";
	int choice = checkIntInput(sentence);
	return choice;
}

int adminMainMenu()
{
	cout << "Welcome back admin, please select a function" << endl;
	cout << "1) Add Tutor" << endl;
	cout << "2) Display Tutor" << endl;
	cout << "3) Sort Tutor" << endl;
	cout << "4) Search Tutor" << endl;
	cout << "5) Modify Tutor" << endl;
	cout << "6) Termination or Delete Tutor" << endl;
	cout << "0) Logout" << endl;
	string sentence = "Enter your choice: ";
	int choice = checkIntInput(sentence);
	return choice;
}


int addMenu()
{
	cout << "Where you want to add?" << endl;
	cout << "1) Add to First" << endl;
	cout << "2) Add to Last" << endl;
	string sentence = "Enter your choice: ";
	int choice = checkIntInput(sentence);
	return choice;
}

int sortMenu()
{
	cout << "How do you want to sort?" << endl;
	cout << "1) Sort by Tutors ID" << endl;
	cout << "2) Sort by Pay Rate " << endl;
	cout << "3) Sort by Overall Performance" << endl;
	string sentence = "Enter your choice: ";
	int choice = checkIntInput(sentence);
	return choice;
}

int searchMenu()
{
	cout << "How do you want to search?" << endl;
	cout << "1) Search by Tutor ID" << endl;
	cout << "2) Search by overall performance" << endl;
	string sentence = "Enter your choice: ";
	int choice = checkIntInput(sentence);
	return choice;
}

int deleteMenu()
{
	cout << "Which function you need?" << endl;
	cout << "1) Terminate all expired tutors" << endl;
	cout << "2) Delete specific tutor data" << endl;
	string sentence = "Enter your choice: ";
	int choice = checkIntInput(sentence);
	return choice;
}






