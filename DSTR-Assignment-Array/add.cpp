#include <vector>
#include <iostream>
#include "add.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "validate.h"
#include "date.h"
#include "display.h"
using namespace std;

Tutor addingInterface(vector<Tutor> arr)
{
	string date;
	/*std::string ID;
	std::string name;
	float payRate;
	float rating;
	std::string phone;
	Date joinDate;
	Date terminateDate;
	Center* center;
	Subject* subject;*/

	Tutor tutor;
	
	cout << "Please enter information below" << endl;
	while (true)
	{
		
		cout << "Tutor ID (TXX): ";
		cin >> tutor.ID;
		if (!isTutorIDFormatCorrect(tutor.ID)){continue;}
		if (isTutorIDExisted(arr,tutor.ID)){continue;}
		break;
	}
	
	cout << "Tutor Name: ";
	cin >> tutor.name;

	
	while (true)
	{
		string setence = "Pay Rate (40 ~ 80): ";
		tutor.payRate = checkIntInput(setence);
		if (!isPayRateRangeValid(tutor.payRate)) { continue;}
		break;
	}

	tutor.rating = 0;
	tutor.countRate = 0;
	
	while (true)
	{
		cout << "Phone Number(10~11 digits): ";
		cin >> tutor.phone;
		
		if (!isPhoneFormatValid(tutor.phone)) { continue; }
		break;
	}
	
	while (true)
	{
		
		cout << "Join Date (dd/MM/yyyy): ";
		cin >> date;
		
		if (!isDateFormatValid(date)) { continue; }
		tutor.joinDate = date;
		break;
	}
	tutor.terminateDate = Date("-");

	while (true)
	{
		cout << "Please choose Center ID from list below" << endl;
		DisplayCenter();
		cout << "Center ID: ";
		cin >> tutor.center->ID;
		if (!(isCenterIDExisted(tutor.center->ID))) { continue; }
		break;
	}

	while (true)
	{
		cout << "Please choose Subject ID from list below " << endl;
		DisplaySubject();
		cout << "Subject ID: ";
		cin >> tutor.subject->ID;
		
		if (!(isSubjectIDExisted(tutor.subject->ID))) { continue; }
		break;
	}

	return tutor;
	
}

void addToBack(vector<Tutor> arr, Tutor tutor)
{
	arr.push_back(tutor);
}

void addToFront(vector<Tutor> arr, Tutor tutor)
{
	arr.insert(arr.begin(), tutor);
}
