#include <vector>
#include <iostream>
#include "add.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "validate.h"
#include "date.h"
using namespace std;

void addingInterface(vector<Tutor> arr)
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
		cout << endl;
		if (!isTutorIDFormatCorrect(tutor.ID)){continue;}
		if (isTutorIDExisted(arr,tutor.ID)){continue;}
		break;
	}
	
	cout << "Tutor Name: ";
	cin >> tutor.name;
	cout << endl;
	
	while (true)
	{
		string setence = "Pay Rate (RM40 ~ RM80): ";
		tutor.payRate = checkIntInput(setence);
		if (!isPayRateRangeValid(tutor.payRate)) { continue;}
		break;
	}

	tutor.rating = 0;
	
	while (true)
	{
		cout << "Phone Number(10~11 digits): ";
		cin >> tutor.phone;
		cout << endl;
		if (!isPhoneFormatValid(tutor.phone)) { continue; }
		break;
	}
	
	while (true)
	{
		
		cout << "Join Date (dd/MM/yyyy): ";
		cin >> date;
		cout << endl;
		if (!isDateFormatValid(date)) { continue; }
		tutor.joinDate = date;
		break;
	}
	tutor.terminateDate = Date("-");



	

	
}
