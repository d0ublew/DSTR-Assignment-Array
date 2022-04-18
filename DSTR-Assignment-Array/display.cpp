#include <iostream>
#include <vector>
#include <limits>
#include "tutor.h"
#include "center.h"
#include "subject.h"
#include "date.h"
#include "display.h"
#include "validate.h"

using namespace std;


//displaying tutor
void DisplayTutor(vector<Tutor> &arr, bool isAdmin) 
{
    size_t size = arr.size();
    size_t step = 5; //how many tutor being display per page

    if (isAdmin)
        step = 3; //set tutor display only 3 per page
    
    int choice = 0;
    size_t start = 0; //start of each page display
    size_t end = step; //end of each page display

    while (true)
    {
        system("cls || clear");//clear screen
        for (size_t i = start; i < end && i < size; i++)
        {
            cout << "TutorID: " << arr.at(i).ID << endl;
            cout << "Tutur Name: " << arr.at(i).name << endl;
            //if its not admin then only show
            //tutor id and name
            if (!isAdmin) 
            {
                cout << endl;
                continue;
            }

            cout << "PayRate: " << arr.at(i).payRate << endl;
            cout << "Rating: " << arr.at(i).rating << endl;
            cout << "Phone Number: " << arr.at(i).phone << endl;
            cout << "Joined Date: " << arr.at(i).joinDate.ToString() << endl;
            cout << "Termination Date: " <<
                arr.at(i).terminateDate.ToString() << endl;
            cout << "Center ID: " << arr.at(i).center->ID << endl;
            cout << "Center Name: " << arr.at(i).center->name << endl;
            cout << "Subject ID: " << arr.at(i).subject->ID << endl;
            cout << "Subject Name: " << arr.at(i).subject->name << endl;
            cout << endl;
        }

        string sentence = "Prev or Next (0 to Prev 1 to Next 2 to Exit): ";
        choice = checkIntInput(sentence);
        //the statement to move forward and back
        if (choice == 1)
        {
            if (end <= size)
            {
                start += step;
                end += step;
            }
        }
        else if (choice == 0)
        {
            if (start >= step)
            {
                start -= step;
                end -= step;
            }
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

//displaying subject in a list
void DisplaySubject()
{
    vector<Subject> arr = _SUBJECT;
    size_t size = arr.size();
    cout << "List of Subject's Information" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "SubjectID: " << arr[i].ID << endl;
        cout << "Subject Name: " << arr[i].name << endl;
        cout << endl;
    }
}

//displaying center in a list
void DisplayCenter()
{
    vector<Center> arr = _CENTER;
    size_t size = arr.size();
    cout << "List of Center's Information" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "CenterID: " << arr[i].ID << endl;
        cout << "Center Name: " << arr[i].name << endl;
        cout << endl;
    }
}
