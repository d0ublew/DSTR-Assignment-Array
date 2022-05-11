#include <iostream>
#include <string>

#include "display.h"
#include "file2struct.h"
#include "modify.h"
#include "search.h"
#include "sort.h"
#include "student_menu.h"
#include "tutor.h"
#include "validate.h"

using namespace std;

void studentRatingMenu(vector<Tutor *> &tutorV)
{
    while (true)
    {
        clearScreen();
        cout << "Welcome student what you want to do?" << endl;
        cout << "1) Rate a tutor" << endl;
        cout << "2) Display list of tutor" << endl;
        cout << "0) Log Out" << endl;
        string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (isChoiceInMenuRange(choice, 2))
        {
            switch (choice)
            {
            case 0:
                return;

            case 1:
                studentSearchingTutorMenu(tutorV);
                break;
            case 2:
                DisplayTutor(tutorV, false);
                break;
            }
        }
    }
}

void studentSearchingTutorMenu(vector<Tutor *> &tutorV)
{
    while (true)
    {
        Tutor query;
        int (*CompareFn)(Tutor &, Tutor &) = nullptr;
        std::cout << "Enter Tutor ID (TXX): ";
        std::getline(std::cin, query.ID);
        CompareFn = &CompareTutorID;
        std::vector<Tutor *> result = searchTutor(tutorV, query, (*CompareFn));
        if (result.size() != 0)
        {
            modifyTutor(result, false);
            tutorToFile(tutorV, TUTOR_FILE);
            return;
        }
        else
        {
            cout << "No Tutor Found please try another Tutor ID" << endl;
            Enter();
            return;
        }
    }
}
