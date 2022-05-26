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

void studentRatingMenu(std::vector<Tutor *> &tutorV)
{
    while (true)
    {
        clearScreen();
        std::cout << "Welcome student what you want to do?" << std::endl;
        std::cout << "1) Rate a tutor" << std::endl;
        std::cout << "2) Display list of tutor" << std::endl;
        std::cout << "0) Log Out" << std::endl;
        std::string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 2))
            continue;
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

void studentSearchingTutorMenu(std::vector<Tutor *> &tutorV)
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
            std::cout << "No Tutor Found please try another Tutor ID" << std::endl;
            Enter();
            return;
        }
    }
}
