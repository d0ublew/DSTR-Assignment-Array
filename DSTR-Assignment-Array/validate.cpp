#include <vector>
#include <iostream>
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "validate.h"
#include <limits>
#include "date.h"


using namespace std;

bool isTutorIDExisted(vector<Tutor> arr, string ID) //checkExistingTutorID existed or not
{

	if (ID == getTutorByID(arr, ID)->ID)
	{
		cout << "Tutor ID already existed, please enter again" << endl;
		return true;
	}
	
	return false;
	
}

bool isTutorIDFormatCorrect(string ID) //check tutorID format
{
	
	if (ID[0] == 'T' && (ID[1] >= '0' && ID[1] <= '9') && (ID[2] >= '0' && ID[2] <= '9'))
	{
		return true;
	}
	cout << "TutorID Format is wrong please insert as \"TXX\" " << endl;
	return false;
}

bool isCenterIDExisted(string ID)
{
	if (ID == getCenterByID(_CENTER, ID)->ID)
	{
		return true;
	}
	cout << "Center ID is not valid, please enter again" << endl;
	return false;
}

bool isSubjectIDExisted(string ID)
{
	if (ID == getSubjectByID(_SUBJECT, ID)->ID)
	{
		return true;
	}
	cout << "Subject ID is not valid, please enter again" << endl;
	return false;
}

bool isDateFormatValid(string d)
{
	//dd/mm/yyyy
	if (!(d[2] == '/' && d[4] == '/' && d[6] == '/'))
	{
		cout << "Invalid Date format please use (dd/MM/yyyy)" << endl;
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 4 || i == 6)
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
	
	if (!(date.month > 0 && date.month <= 12))
	{
		cout << "Invalid Month (01~12)" << endl;
		return false;
	}

	if (!(date.year >= 1900 && date.year <= 9999))
	{
		cout << "Invalid Year" << endl;
		return false;
	}

	if (date.month == 1 )
	{
		numOfDay = 31;
	}
	else if (date.month == 2)
	{
		if (date.year % 4 == 0) {
			numOfDay = 29;
		}
		else
		{
			numOfDay = 28;
		}
	}
	else if (date.month == 3)
	{
		numOfDay = 31;
	}
	else if (date.month == 4)
	{
		numOfDay = 30;
	}
	else if (date.month == 5)
	{
		numOfDay = 31;
	}
	else if (date.month == 6)
	{
		numOfDay = 30;
	}
	else if (date.month == 7)
	{
		numOfDay = 31;
	}
	else if (date.month == 8)
	{
		numOfDay = 31;
	}
	else if (date.month == 9)
	{
		numOfDay = 30;
	}
	else if (date.month == 10)
	{
		numOfDay = 31;
	}
	else if (date.month == 11)
	{
		numOfDay = 30;
	}
	else if (date.month == 12)
	{
		numOfDay = 31;
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
	cout << "Invalid PayRate Range please insert between RM40 to RM80" << endl;
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

int checkIntInput(string sentence) // To verify input type, if its not integer it will ask the user to input again //PLEASE USE THIS CODE TO VERIFY INTEGER INPUT
{

	int input;
	while (std::cout << sentence && !(std::cin >> input)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, number only, please re-enter.\n";
	}

	return input;
}


