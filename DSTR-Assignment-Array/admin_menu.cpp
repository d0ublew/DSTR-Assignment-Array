#include <iostream>
#include <string>

using namespace std;

int checkIntInput(string sentence);
int startMenu();


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





int checkIntInput(string sentence)
{
	
	int input;
	while (std::cout << sentence && !(std::cin >> input)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, number only, please re-enter.\n";
	}

	return input;
}

