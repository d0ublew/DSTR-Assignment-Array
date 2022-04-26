#include <iostream>
#include <vector>

#include "date.h"
#include "delete.h"
#include "display.h"
#include "tutor.h"
#include "validate.h"

using namespace std;

void DeleteTutor(std::vector<Tutor *> &subTutorV, std::string ID)
{
    std::vector<Tutor *>::iterator it = subTutorV.begin();

    while (it != subTutorV.end() && (*it)->ID != ID)
    {
        it++;
    }

    if (it == subTutorV.end())
    {
        std::cout << "No matching record found.\n";
        Enter();
        return;
    }

    while (true)
    {
        {
            std::vector<Tutor *> temp(it, it + 1);
            clearScreen();
            SubDisplay(temp, 0, 1, false);
        }
        int choice = getIntInput("Do you want to proceed? (1 = Yes / 0 = No): ");
        if (isChoiceInMenuRange(choice, 1))
        {
            if (choice == 1)
            {
                subTutorV.erase(it);
                std::cout << "Delete successful\n";
                Enter();
                return;
            }
            else if (choice == 0)
            {
                return;
            }
        }
    }
}

void DeleteTerminatedTutor(std::vector<Tutor *> &tutorV)
{
    Date today = Date();
    today.Today();
    Date sixMonth = today.SixMonthBack();

    std::vector<size_t> idx;

    puts("");
    for (size_t i = 0; i < tutorV.size(); i++)
    {
        Date term = tutorV.at(i)->terminateDate;
        if (!term.Empty() && term < sixMonth)
        {
            idx.insert(idx.begin(), i);
            SubDisplay(tutorV, 0, 1, false);
        }
    }

    if (idx.size() == 0)
    {
        std::cout << "No tutor to be deleted.\n";
        Enter();
        return;
    }

    while (true)
    {
        int choice = getIntInput("These tutors will be deleted, proceed? (1 = Yes / 0 = No): ");
        if (isChoiceInMenuRange(choice, 1))
        {
            if (choice == 1)
            {
                for (size_t i = 0; i < idx.size(); i++)
                {
                    delete tutorV.at(idx.at(i));
                    tutorV.erase(tutorV.begin() + idx.at(i));
                }
                std::cout << "Delete successful\n";
                Enter();
                return;
            }
            else if (choice == 0)
            {
                return;
            }
        }
    }
}
