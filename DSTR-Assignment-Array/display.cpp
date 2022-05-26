#include <iostream>
#include <vector>

#include "admin_menu.h"
#include "center.h"
#include "date.h"
#include "display.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

// displaying tutor
void DisplayTutor(std::vector<Tutor *> &tutorV, bool isAdmin)
{
    size_t size = tutorV.size();
    if (size == 0)
    {
        std::cout << "No tutor record to be displayed\n";
        Enter();
        return;
    }
    size_t step = 5; // how many tutor being display per page

    if (isAdmin)
        step = 3; // set tutor display only 3 per page

    int choice = 0;
    size_t start = 0;
    size_t end = step;

    while (true)
    {
        clearScreen();
        SubDisplay(tutorV, start, end, isAdmin);
        std::string sentence = "Prev or Next (1 to Prev 2 to Next 0 to Exit): ";
        choice = getIntInput(sentence);
        // the statement to move forward and back
        if (choice == 2)
        {
            if (end < size)
            {
                start += step;
                end += step;
            }
        }
        else if (choice == 1)
        {
            if (start >= step)
            {
                start -= step;
                end -= step;
            }
        }
        else if (choice == 0)
        {
            break;
        }
    }
}

// displaying subject in a list
void DisplaySubject()
{
    std::vector<Subject> arr = _SUBJECT;
    size_t size = arr.size();
    std::cout << "List of Subject's Information" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Subject ID: " << arr[i].ID << std::endl;
        std::cout << "Subject Name: " << arr[i].name << std::endl;
        std::cout << std::endl;
    }
}

// displaying center in a list
void DisplayCenter()
{
    std::vector<Center> arr = _CENTER;
    size_t size = arr.size();
    std::cout << "List of Center's Information" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Center ID: " << arr[i].ID << std::endl;
        std::cout << "Center Name: " << arr[i].name << std::endl;
        std::cout << std::endl;
    }
}

void SubDisplay(std::vector<Tutor *> &tutorV, size_t start, size_t end, bool isAdmin)
{
    for (size_t i = start; i < end && i < tutorV.size(); i++)
    {
        std::cout << "Tutor ID: " << tutorV.at(i)->ID << std::endl;
        std::cout << "Tutor Name: " << tutorV.at(i)->name << std::endl;
        // if its not admin then only show
        // tutor id and name
        if (!isAdmin)
        {
            std::cout << std::endl;
            continue;
        }

        std::cout << "Pay Rate: " << tutorV.at(i)->payRate << std::endl;
        std::cout << "Rating: " << tutorV.at(i)->rating << std::endl;
        std::cout << "Phone Number: " << tutorV.at(i)->phone << std::endl;
        std::cout << "Address: " << tutorV.at(i)->address << std::endl;
        std::cout << "Joined Date: " << tutorV.at(i)->joinDate.ToString() << std::endl;
        std::cout << "Termination Date: " << tutorV.at(i)->terminateDate.ToString() << std::endl;
        std::cout << "Center ID: " << tutorV.at(i)->center->ID << std::endl;
        std::cout << "Center Name: " << tutorV.at(i)->center->name << std::endl;
        std::cout << "Subject ID: " << tutorV.at(i)->subject->ID << std::endl;
        std::cout << "Subject Name: " << tutorV.at(i)->subject->name << std::endl;
        std::cout << std::endl;
    }
}

void clearScreen()
{
    system("cls || clear");
}
