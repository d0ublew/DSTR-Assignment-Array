#include <iostream>
#include <string>
#include "validate.h"
#include "student_menu.h"
#include "display.h"
#include "tutor.h"
#include "file2struct.h"
#include "add.h"

using namespace std;

void startMenu();
void adminMainMenu();
bool adminLogin();
void addMenu();
void sortMenu();
void searchMenu();
void deleteMenu();





void startMenu()
{
	
	while (true)
	{
		cout << "Welcome to eXcel Tuition Centre" << endl;
		cout << "Who are you?" << endl;
		cout << "1) Admin" << endl;
		cout << "2) Student" << endl;
		cout << "0) Exit" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2)) 
		{
			//code here
			switch (choice)
			{
			case 0:
				cout << "Thank you for using this system" << endl;
				return;

			case 1:
				if (adminLogin()) { adminMainMenu(); }
				break;
			case 2:
				studentRatingMenu();
				break;
			}

		}
	}
	
}
bool adminLogin()
{

	string username;
	string password;
	while (true)
	{
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		if (username == "admin" && password == "abc")
		{
			return true;
		}
		else
		{
			cout << "Invalid Password" << endl;
			continue;
		}
	}
	
}
void adminMainMenu()
{
	
	while (true)
	{
		std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
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
		if (isChoiceInMenuRange(choice, 6))
		{
			switch (choice)
			{
			case 0:
				return;
				
			case 1:
				addMenu();
				break;
			case 2:
				DisplayTutor(tutorV);
				break;
			case 3:
				sortMenu();
				break;
			case 4:
				searchMenu();
				break;
			case 5:
				//Modify method call here
				// please delete this cout after implementing modify
				cout << "No yet impemented modify" << endl;
				break;
			case 6:
				deleteMenu();
				break;
			}
			
		}
	}
	
}


void addMenu()
{
	
	while (true)
	{
		std::vector<Tutor> tutorV = fileToTutor(TUTOR_FILE);
		Tutor tutor;
		cout << "Where you want to add?" << endl;
		cout << "1) Add to First" << endl;
		cout << "2) Add to Last" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			//code here
			switch (choice)
			{
			case 0:
				return;

			case 1:
				//code here
				tutor = addingInterface(tutorV);
				addToFront(tutorV, tutor);
				tutorToFile(tutorV, TUTOR_FILE);
				cout << "Tutor Added to Front Succesfully!";
				break;
			case 2:
				//code here
				tutor = addingInterface(tutorV);
				addToBack(tutorV, tutor);
				tutorToFile(tutorV, TUTOR_FILE);
				cout << "Tutor Added to Back Succesfully!";
				break;
			}
			
		}
	}
	
}

void sortMenu()
{
	while (true)
	{
		cout << "How do you want to sort?" << endl;
		cout << "1) Sort by Tutors ID" << endl;
		cout << "2) Sort by Pay Rate " << endl;
		cout << "3) Sort by Overall Performance" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 3))
		{
			//code here
		}
	}
	
}

void searchMenu()
{
	while (true)
	{
		cout << "How do you want to search?" << endl;
		cout << "1) Search by Tutor ID" << endl;
		cout << "2) Search by overall performance" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			//code here
		}
	}
	
}

void deleteMenu()
{
	while (true)
	{
		cout << "Which function you need?" << endl;
		cout << "1) Terminate all expired tutors" << endl;
		cout << "2) Delete specific tutor data" << endl;
		cout << "0) Previous Page" << endl;
		string sentence = "Enter your choice: ";
		int choice = checkIntInput(sentence);
		if (isChoiceInMenuRange(choice, 2))
		{
			//code here
		}
	}
	
}






