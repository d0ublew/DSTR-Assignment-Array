#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "admin.h"
#include "center.h"
#include "date.h"
#include "student.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

bool isTutorIDExisted(std::vector<Tutor *> &arr, std::string ID)
{
    Tutor *t = getTutorByID(arr, ID);
    if (t == nullptr)
        return false;
    if (ID != t->ID)
        return false;
    std::cout << "Tutor ID already existed, please enter again\n";
    return true;
}

bool isTutorIDFormatCorrect(std::string ID)
{
    if (ID.length() == 3 && ID[0] == 'T' && (ID[1] >= '0' && ID[1] <= '9') && (ID[2] >= '0' && ID[2] <= '9'))
    {
        return true;
    }
    std::cout << "TutorID Format is wrong please insert as \"TXX\" \n";
    return false;
}

bool isCenterExisted(Center *c)
{
    /* vector<Center> arr = _CENTER; */
    if (c != nullptr)
        return true;
    std::cout << "Center ID is not valid, please enter again\n";
    return false;
}

bool isSubjectExisted(Subject *s)
{
    /* vector<Subject> arr = _SUBJECT; */
    if (s != nullptr)
        return true;
    std::cout << "Subject ID is not valid, please enter again\n";
    return false;
}

bool isAdminUsernameExisted(vector<Admin> &arr, string username)
{
    Admin *t = getAdminByUsername(arr, username);
    if (t == nullptr)
        return false;
    if (username != t->username)
        return false;
    cout << "Admin Username already existed, please enter again" << endl;
    return true;
}

bool isStudentUsernameExisted(vector<Student> &arr, string username)
{
    Student *t = getStudentByUsername(arr, username);
    if (t == nullptr)
        return false;
    if (username != t->username)
        return false;
    cout << "Student Username already existed, please enter again" << endl;
    return true;
}
bool isDateValid(string d)
{
    // dd/mm/yyyy
    if (!(d.length() == 10))
    {
        std::cout << "Invalid format please use (dd/MM/yyyy)\n";
        return false;
    }
    if (!(d[2] == '/' && d[5] == '/'))
    {
        std::cout << "Invalid Date format please use (dd/MM/yyyy)\n";
        return false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
        {
            continue;
        }
        if (!(d[i] >= '0' && d[i] <= '9'))
        {
            std::cout << "Invalid Date format please use (dd/MM/yyyy)\n";
            return false;
        }
    }

    Date date(d);
    int numOfDay;

    if (!(date.year >= 1900 && date.year <= 9999))
    {
        std::cout << "Invalid Year\n";
        return false;
    }

    if (!(date.month > 0 && date.month <= 12))
    {
        std::cout << "Invalid Month (01~12)\n";
        return false;
    }

    if (date.month == 2)
    {
        numOfDay = 28;
        if (isLeap(date.year))
        {
            numOfDay = 29;
        }
    }
    else if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 ||
             date.month == 10 || date.month == 12)
    {
        numOfDay = 31;
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
        numOfDay = 30;
    else
    {
        numOfDay = 0;
    }

    if (!(date.day > 0 && date.day <= numOfDay))
    {
        std::cout << "Invalid Day\n";
        return false;
    }
    return true;
}

bool isPhoneFormatValid(std::string p)
{
    if (!(p.length() >= 10 && p.length() <= 11))
    {
        std::cout << "Invalid Phone Number Length\n";
        return false;
    }

    for (size_t i = 0; i < p.length(); i++)
    {
        if (!(p[i] >= '0' && p[i] <= '9'))
        {
            std::cout << "Invalid phone number\n";
            return false;
        }
    }
    return true;
}

bool isPayRateRangeValid(float payRate)
{
    if (payRate >= 40 && payRate <= 80)
    {
        return true;
    }
    std::cout << "Invalid PayRate Range please insert between 40 to 80\n";
    return false;
}

bool isRatingRateRangeValid(float rate)
{
    if (rate >= 1 && rate <= 5)
    {
        return true;
    }
    std::cout << "Invalid rating Range please insert between 1 to 5\n";
    return false;
}

/**
 * To verify input type, if its not integer it will ask the user to input again
 * PLEASE USE THIS CODE TO VERIFY INTEGER INPUT
 */
int getIntInput(std::string sentence)
{
    int input = 0;
    while (std::cout << sentence && !(std::cin >> input))
    {
        std::cin.clear(); // clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); // discard input
        std::cout << "Invalid input, number only, please re-enter.\n";
    }
    clearInputBuffer();

    return input;
}

float getFloatInput(std::string sentence)
{
    float input = 0;
    while (std::cout << sentence && !(std::cin >> input))
    {
        std::cin.clear(); // clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); // discard input
        std::cout << "Invalid input, number only, please re-enter.\n";
    }
    clearInputBuffer();

    return input;
}

void clearInputBuffer()
{
    while (getchar() != '\n')
    {
    }
}

void Enter()
{
    std::cout << "Press ENTER to continue";
    clearInputBuffer();
}

bool isLeap(int year)
{
    if (year % 4 != 0 || (year % 400 != 0 && year % 100 == 0))
        return false;
    return true;
}

bool isChoiceInMenuRange(int choice, int end)
{
    if (choice >= 0 && choice <= end)
    {
        return true;
    }
    std::cout << "Invalid Choice\n";
    Enter();
    return false;
}

bool isSpaceExisted(string s)
{
    if (s.find(' ') != string::npos)
    {
        return true;
    }
    return false;
}
