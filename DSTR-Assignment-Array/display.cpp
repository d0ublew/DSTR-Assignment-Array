#include <iostream>
#include "tutor.h"

extern TutorArr* TUTOR_ARR;


using namespace std;
void DisplayTutor()
{
	Tutor* arr = TUTOR_ARR->arr;
	
	cout << arr[0].ID << endl;
	cout << arr[0].name << endl;

}