#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

#include "admin.h"
#include "center.h"
#include "date.h"
#include "delete.h"
#include "display.h"
#include "file2struct.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

using namespace std;

void Display(vector<Tutor> &arr, bool isAdmin)
{
    size_t size = arr.size();
    size_t step = 5; // how many tutor being display per page

    if (isAdmin) step = 3; // set tutor display only 3 per page

    int choice = 0;
    size_t start = 0;  // start of each page display
    size_t end = step; // end of each page display

    while (true)
    {
        system("cls || clear"); // clear screen
        for (size_t i = start; i < end && i < size; i++)
        {
            cout << "Tutor ID: " << arr.at(i).ID << endl;
            cout << "Tutor Name: " << arr.at(i).name << endl;
            // if its not admin then only show
            // tutor id and name
            if (!isAdmin)
            {
                cout << endl;
                continue;
            }

            cout << "Pay Rate: " << arr.at(i).payRate << endl;
            cout << "Rating: " << arr.at(i).rating << endl;
            cout << "Phone Number: " << arr.at(i).phone << endl;
            cout << "Joined Date: " << arr.at(i).joinDate.ToString() << endl;
            cout << "Termination Date: " << arr.at(i).terminateDate.ToString() << endl;
            cout << "Center ID: " << arr.at(i).center->ID << endl;
            cout << "Center Name: " << arr.at(i).center->name << endl;
            cout << "Subject ID: " << arr.at(i).subject->ID << endl;
            cout << "Subject Name: " << arr.at(i).subject->name << endl;
            cout << endl;
            string sentence = "Do you Want To Delete This Record(1 = Yes / 0 = No) ?:  ";
            choice = getIntInput(sentence);
            if (choice == 1)
            {
            }
            else if (choice == 0)
            {
                return;
            }
            else
            {
                system("CLS");
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Invalid Input! Please Type Valid Input!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

                return;
            }
        }
    }
}
