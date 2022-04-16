#include <vector>
#include <iostream>
#include "add.h"
#include "tutor.h"
#include "subject.h"
#include "center.h"
#include "validate.h"

using namespace std;

void addingInterface(vector<Tutor> arr)
{
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
	
}
