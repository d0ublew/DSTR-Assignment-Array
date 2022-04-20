#include <iostream>
#include <string>
#include "validate.h"
#include "student_menu.h"


using namespace std;

//bool studentLogin()
//{
//  while (true)
//  {
//
//  }
//
//}
void studentRatingMenu();


void studentRatingMenu()
{
    cout << "Welcome student what you want to do?" << endl;
    cout << "1) Rate a tutor" << endl;
    cout << "0) Log Out" << endl;
    string sentence = "Enter your choice: ";
    int choice = checkIntInput(sentence);
    if (isChoiceInMenuRange(choice, 1))
    {
        //code here
    }
    
}
