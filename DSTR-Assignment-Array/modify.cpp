#include <iostream>
#include <vector>

#include "admin.h"
#include "admin_menu.h"
#include "center.h"
#include "date.h"
#include "display.h"
#include "file2struct.h"
#include "modify.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

using namespace std;

void DisplayInModify(vector<Tutor> &arr) {
    size_t size = arr.size();
    size_t step = 5; // how many tutor being display per page

    /* if (isAdmin) step = 3; // set tutor display only 3 per page */

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
            /* if (!isAdmin) { */
            /*     cout << endl; */
            /*     continue; */
            /* } */

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
            string sentence =
                "Do you Want To Modify This Record(1 = Yes / 0 = No) ?:  ";
            choice = getIntInput(sentence);

            if (choice == 1) {
                int input;
                cout << "1.Change Phone Number" << endl;
                cout << "2.Change Address" << endl;
                cout << "3.Set Termination Date" << endl;
                input = getIntInput("please input your choice:");
                if (input == 1) {
                    string phone;
                    while (true) {
                        cout << "input new phone:";
                        cin >> phone;

                        if (isPhoneFormatValid(phone)) {
                            arr.at(i).phone = phone;
                        } else {
                            cout << "Please Inpur Correct Input" << endl;
                            continue;
                        }
                        break;
                    }

                }

                else if (input == 3) {
                    string date;
                    while (true) {
                        cout << "input termination date of this tutor:" << endl;
                        cin >> date;
                        if (isDateValid(date)) {
                            arr.at(i).terminateDate = date;

                        } else {
                            cout << "Please Inpur Correct Input" << endl;
                            continue;
                        }
                        break;
                    }
                } else {
                    return;
                }

            } else if (choice == 0) {
                return;
            } else {
                system("CLS");
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                     << endl;
                cout << "Invalid Input! Please Type Valid Input!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                     << endl;

                return;
            }
        }
    }
}

void modifyTutor(Tutor *tutor) {
    while (true) {
        clearScreen();
        cout << "Tutor ID: " << tutor->ID << endl;
        cout << "Tutor Name: " << tutor->name << endl;
        cout << "Pay Rate: " << tutor->payRate << endl;
        cout << "Rating: " << tutor->rating << endl;
        cout << "Phone Number: " << tutor->phone << endl;
        cout << "Address: " << tutor->address << endl;
        cout << "Joined Date: " << tutor->joinDate.ToString() << endl;
        cout << "Termination Date: " << tutor->terminateDate.ToString() << endl;
        cout << "Center ID: " << tutor->center->ID << endl;
        cout << "Center Name: " << tutor->center->name << endl;
        cout << "Subject ID: " << tutor->subject->ID << endl;
        cout << "Subject Name: " << tutor->subject->name << endl;
        cout << endl;
        int choice = getIntInput(
            "Do you want to modify this record (1 = Yes / 0 = No): ");
        if (isChoiceInMenuRange(choice, 1)) {
            if (choice == 1) {
                std::cout << "Modify:\n";
                std::cout << "1. Phone Number\n";
                std::cout << "2. Address\n";
                std::cout << "3. Termination Date\n";
                std::cout << "0. Back\n";
                bool valid = false;
                while (!valid) {
                    int option = getIntInput("Choose what to be modified: ");
                    if (isChoiceInMenuRange(option, 3)) {
                        if (option == 1) {
                            string phone;
                            while (true) {
                                std::getline(std::cin, phone);
                                if (isPhoneFormatValid(phone)) {
                                    tutor->phone = phone;
                                    valid = true;
                                    break;
                                } else {
                                    continue;
                                }
                            }
                        } else if (option == 2) {
                            std::getline(std::cin, tutor->address);
                            valid = true;
                        } else if (option == 3) {
                            string date;
                            while (true) {
                                std::getline(std::cin, date);
                                if (isDateValid(date)) {
                                    tutor->terminateDate = date;
                                    valid = true;
                                    break;
                                } else {
                                    continue;
                                }
                            }
                        } else if (option == 0) {
                            valid = true;
                        }
                    } else {
                        continue;
                    }
                }
            } else if (choice == 0) {
                return;
            }
        }
    }
}
