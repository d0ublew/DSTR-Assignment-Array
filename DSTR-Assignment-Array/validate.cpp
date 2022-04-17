#include <vector>
#include <iostream>
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "validate.h"
#include <limits>
#include <string>
#include "date.h"
#include "admin.h"
#include "student.h"



using namespace std;

bool isTutorIDExisted(vector<Tutor> &arr, string ID) //checkExistingTutorID existed or not
{
    Tutor* t = getTutorByID(arr, ID);
	if (t == nullptr) return false;
    if (ID != t->ID) return false;
    cout << "Tutor ID already existed, please enter again" << endl;
    return true;
}

bool isTutorIDFormatCorrect(string ID) //check tutorID format
{
	
	if (ID.length() == 3 && ID[0] == 'T' && (ID[1] >= '0' && ID[1] <= '9') &&
            (ID[2] >= '0' && ID[2] <= '9'))
	{
		return true;
	}
	cout << "TutorID Format is wrong please insert as \"TXX\" " << endl;
	return false;
}

bool isCenterExisted(Center* c)
{
	/* vector<Center> arr = _CENTER; */
    if (c != nullptr) return true;
    cout << "Center ID is not valid, please enter again" << endl;
	return false;
}

bool isSubjectExisted(Subject* s)
{
	/* vector<Subject> arr = _SUBJECT; */
    if (s != nullptr) return true;
    cout << "Subject ID is not valid, please enter again" << endl;
	return false;
}

bool isAdminUsernameExisted(vector<Admin>& arr, string username)
{
	Admin* t = getAdminByUsername(arr,username);
	if (t == nullptr) return false;
	if (username != t->username) return false;
	cout << "Admin Username already existed, please enter again" << endl;
	return true;
}

bool isStudentUsernameExisted(vector<Student>& arr, string username)
{
	Student* t = getStudentByUsername(arr, username);
	if (t == nullptr) return false;
	if (username != t->username) return false;
	cout << "Student Username already existed, please enter again" << endl;
	return true;
}
bool isDateFormatValid(string d)
{
	//dd/mm/yyyy
	if (!(d.length() == 10))
	{
		cout << "Invalid format please use (dd/MM/yyyy)" << endl;
		return false;
	}
	if (!(d[2] == '/' && d[5] == '/'))
	{
		cout << "Invalid Date format please use (dd/MM/yyyy)" << endl;
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 5)
		{
			continue;
		}
		if (!(d[i] >= '0' && d[i] <= '9'))
		{
			cout << "Invalid Date format please use (dd/MM/yyyy)" << endl;
			return false;
		}
	}

	Date date(d);
	int numOfDay;

	if (!(date.year >= 1900 && date.year <= 9999))
	{
		cout << "Invalid Year" << endl;
		return false;
	}
	
	if (!(date.month > 0 && date.month <= 12))
	{
		cout << "Invalid Month (01~12)" << endl;
		return false;
	}

    if (date.month == 2) {
        numOfDay = 28;
		if (isLeap(date.year)) {
			numOfDay = 29;
		}
    }
    else if (
            date.month == 1 ||
            date.month == 3 ||
            date.month == 5 ||
            date.month == 7 ||
            date.month == 8 ||
            date.month == 10 ||
            date.month == 12
            ) {
        numOfDay = 31;
    }
    else if (
            date.month == 4 ||
            date.month == 6 ||
            date.month == 9 ||
            date.month == 11
            )
        numOfDay = 30;
    else {
        numOfDay = 0;
    }

	if (!(date.day > 0 && date.day <= numOfDay))
	{
		cout << "Invalid Day" << endl;
		return false;
	}
	return true;
}

bool isPhoneFormatValid(string p)
{
	if (!(p.length() >= 10 && p.length() <= 11))
	{
		cout << "Invalid Phone Number Length" << endl;
		return false;
	}

	for (size_t i = 0; i < p.length(); i++)
	{
		if (!(p[i] >= '0' && p[i] <= '9'))
		{
			cout << "Invalid phone number" << endl;
			return false;
		}
	}
	return true;

}

bool isPayRateRangeValid(float payRate)
{
	if (payRate >= 40 && payRate <= 80)
	{
		return true;
	}
	cout << "Invalid PayRate Range please insert between 40 to 80" << endl;
	return false;
}



bool isRatingRateRangeValid(float rate)
{
	if (rate >= 1 && rate <= 5)
	{
		return true;
	}
	cout << "Invalid rating Range please insert between 1 to 5" << endl;
	return false;
}

/**
 * To verify input type, if its not integer it will ask the user to input again
 * PLEASE USE THIS CODE TO VERIFY INTEGER INPUT
 */
int checkIntInput(string sentence)
{

	int input;
	while (std::cout << sentence && !(std::cin >> input)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, number only, please re-enter.\n";
	}
    clearInputBuffer();

	return input;
}

float checkFloatInput(string sentence)
{

	float input;
	while (std::cout << sentence && !(std::cin >> input)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, number only, please re-enter.\n";
	}
    clearInputBuffer();

	return input;
}

void clearInputBuffer() {
    while (getchar() != '\n') {}
}

void Enter() {
    std::cout << "Press ENTER to continue";
    clearInputBuffer();
}


bool isLeap(int year) {
    if (year % 4 != 0 ||
            (year % 400 != 0 && year % 100 == 0)) return false;
    return true;
}

bool isChoiceInMenuRange(int choice, int end)
{
	if (choice >= 0 && choice <= end) { return true; }
	cout << "Invalid Choice" << endl;
    Enter();
	return false;
}

bool isSpaceExisted(string s)
{
	if (s.find(' ') != string::npos)
	{
		return true;
	}
	return false;
}
