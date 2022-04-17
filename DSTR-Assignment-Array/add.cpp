#include <vector>
#include <iostream>
#include <string>
#include "add.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "validate.h"
#include "date.h"
#include "display.h"
using namespace std;

Tutor addingInterface(vector<Tutor> &arr)
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
		getline(cin, tutor.ID);
		if (!isTutorIDFormatCorrect(tutor.ID)){continue;}
		if (isTutorIDExisted(arr, tutor.ID)){continue;}
		break;
	}
	
	cout << "Tutor Name: ";

    // use getline to get name with spaces
    getline(cin, tutor.name);

	
	while (true)
	{
		string setence = "Pay Rate (40 ~ 80): ";
		tutor.payRate = checkFloatInput(setence);
		if (!isPayRateRangeValid(tutor.payRate)) { continue;}
		break;
	}

    // clear trailing linefeed
    while (getchar() != '\n') {}
	tutor.rating = 0;
	tutor.countRate = 0;
	
	while (true)
	{
		cout << "Phone Number(10~11 digits): ";
		getline(cin, tutor.phone);
		
		if (!isPhoneFormatValid(tutor.phone)) { continue; }
		break;
	}
	
	while (true)
	{
		
		cout << "Join Date (dd/MM/yyyy): ";
		getline(cin, date);
		
		if (!isDateFormatValid(date)) { continue; }
		tutor.joinDate = date;
		break;
	}
	tutor.terminateDate = Date("-");

	while (true)
	{
        string ID;
		cout << "Please choose Center ID from list below" << endl;
		DisplayCenter();
		cout << "Center ID: ";
        getline(cin, ID);
        tutor.center = getCenterByID(_CENTER, ID);
		if (!(isCenterExisted(tutor.center))) { continue; }
		break;
	}

	while (true)
	{
        string ID;
		cout << "Please choose Subject ID from list below " << endl;
		DisplaySubject();
		cout << "Subject ID: ";
		getline(cin, ID);
        tutor.subject = getSubjectByID(_SUBJECT, ID);
		if (!(isSubjectExisted(tutor.subject))) { continue; }
		break;
	}

	return tutor;
	
}

void addToBack(vector<Tutor> &arr, Tutor tutor)
{
	arr.push_back(tutor);
}

void addToFront(vector<Tutor> &arr, Tutor tutor)
{
	arr.insert(arr.begin(), tutor);
}
