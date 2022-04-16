
#include <iostream>
#include <string>
using namespace std;








int checkIntInput(string sentence) // To verify input type, if its not integer it will ask the user to input again
{

	int input;
	while (std::cout << sentence && !(std::cin >> input)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, number only, please re-enter.\n";
	}

	return input;
}