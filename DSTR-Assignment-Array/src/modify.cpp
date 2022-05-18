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

void modifyTutor(std::vector<Tutor *> &tutorV, bool isAdmin)
{
    Tutor *tutor = tutorV.at(0);
    int choice;
    while (true)
    {
        clearScreen();
        SubDisplay(tutorV, 0, 1, isAdmin);

        if (isAdmin)
        {
            choice = getIntInput("Do you want to modify this record (1 = Yes / 0 = No): ");
        }
        else
        {
            choice = getIntInput("Do you want to rate this tutor (1 = Yes / 0 = No): ");
        }

        if (!isChoiceInMenuRange(choice, 1)) continue;

        if (choice == 0) return;

        if (!isAdmin && choice == 1)
        {
            while (true)
            {
                float rate;
                rate = getFloatInput("Please give your rate (1.0 ~ 5.0): ");
                if (!isRatingRateRangeValid(rate))
                {
                    continue;
                }

                size_t count_rate = tutor->countRate;
                float tutor_rate = tutor->rating;
                tutor_rate *= count_rate;
                tutor_rate += rate;
                count_rate += 1;
                tutor_rate /= count_rate;
                tutor->rating = tutor_rate;
                tutor->countRate = count_rate;
                cout << "Thank you for your rating" << endl;
                Enter();
                return;
            }
        }
        std::cout << "Modify:\n";
        std::cout << "1. Phone Number\n";
        std::cout << "2. Address\n";
        std::cout << "3. Termination Date\n";
        std::cout << "0. Back\n";
        while (true)
        {
            int option = getIntInput("Choose what to be modified: ");
            if (!isChoiceInMenuRange(option, 3)) continue;
            if (option == 1)
            {
                string phone;
                while (true)
                {
                    std::cout << "New Phone: ";
                    std::getline(std::cin, phone);
                    if (isPhoneFormatValid(phone))
                    {
                        tutor->phone = phone;
                        break;
                    }
                }
            }
            else if (option == 2)
            {
                std::cout << "New Address: ";
                std::getline(std::cin, tutor->address);
            }
            else if (option == 3)
            {
                string date;
                while (true)
                {
                    std::cout << "Terminate date: ";
                    std::getline(std::cin, date);
                    if (isDateValid(date))
                    {
                        tutor->terminateDate = Date(date);
                        break;
                    }
                }
            }
            break;
        }
        std::cout << "Update successful\n";
        Enter();
    }
}
