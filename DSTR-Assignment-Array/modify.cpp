#include "display.h"
#include "center.h"
#include "date.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"
#include "admin.h"
#include "file2struct.h"
#include "modify.h"





#include <iostream>
#include <limits>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;


void DisplayInModify(vector<Tutor>& arr, bool isAdmin) {
    size_t size = arr.size();
    size_t step = 5; // how many tutor being display per page

    if (isAdmin) step = 3; // set tutor display only 3 per page

    int choice = 0;
    size_t start = 0;  // start of each page display
    size_t end = step; // end of each page display

    while (true) {
        system("cls || clear"); // clear screen
        for (size_t i = start; i < end && i < size; i++) {
            cout << "Tutor ID: " << arr.at(i).ID << endl;
            cout << "Tutor Name: " << arr.at(i).name << endl;
            // if its not admin then only show
            // tutor id and name
            if (!isAdmin) {
                cout << endl;
                continue;
            }

            cout << "Pay Rate: " << arr.at(i).payRate << endl;
            cout << "Rating: " << arr.at(i).rating << endl;
            cout << "Phone Number: " << arr.at(i).phone << endl;
            cout << "Joined Date: " << arr.at(i).joinDate.ToString() << endl;
            cout << "Termination Date: " << arr.at(i).terminateDate.ToString()
                << endl;
            cout << "Center ID: " << arr.at(i).center->ID << endl;
            cout << "Center Name: " << arr.at(i).center->name << endl;
            cout << "Subject ID: " << arr.at(i).subject->ID << endl;
            cout << "Subject Name: " << arr.at(i).subject->name << endl;
            cout << endl;
            string sentence = "Do you Want To Modify This Record(1 = Yes / 0 = No) ?:  ";
            choice = getIntInput(sentence);
            
            if (choice == 1) {
                int input;
                cout << "1.Change Phone Number" << endl;
                cout << "2.Change Address" << endl;
                cout << "3.Set Termination Date" << endl;
                input = getIntInput("please input your choice:");
                if (input == 1) {
                    string phone;
                    while (true)
                    {
                        cout << "input new phone:";
                        cin >> phone;

                        if (isPhoneFormatValid(phone)) {
                            arr.at(i).phone = phone;
                        }
                        else {
                            cout << "Please Inpur Correct Input" << endl;
                            continue;
                        }
                        break;
                    }
                    
                         
                }
                
                else if (input == 3) {
                    string date;
                    while (true)
                    {
                        cout << "input termination date of this tutor:" << endl;
                        cin >> date;
                        if (isDateValid(date)) {
                            arr.at(i).terminateDate = date;

                        }
                        else {
                            cout << "Please Inpur Correct Input" << endl;
                            continue;
                        }
                        break;
                    }
                }
                else {
                    return;
                }
                


            }
            else if (choice == 0) {
                return;
            }
            else {
                system("CLS");
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "Invalid Input! Please Type Valid Input!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

                return;

            }
        }
    }
}