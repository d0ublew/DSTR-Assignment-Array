#include <iostream>
#include <vector>

#include "admin_menu.h"
#include "center.h"
#include "date.h"
#include "display.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

using namespace std;

// displaying tutor
void DisplayTutor(vector<Tutor *> &tutorV, bool isAdmin) {
  size_t size = tutorV.size();
  if (size == 0) {
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

  while (true) {
    clearScreen();
    SubDisplay(tutorV, start, end, isAdmin);
    string sentence = "Prev or Next (1 to Prev 2 to Next 0 to Exit): ";
    choice = getIntInput(sentence);
    // the statement to move forward and back
    if (choice == 2) {
      if (end < size) {
        start += step;
        end += step;
      }
    } else if (choice == 1) {
      if (start >= step) {
        start -= step;
        end -= step;
      }
    } else if (choice == 0) {
      break;
    }
  }
}

// displaying subject in a list
void DisplaySubject() {
  vector<Subject> arr = _SUBJECT;
  size_t size = arr.size();
  cout << "List of Subject's Information" << endl;
  for (size_t i = 0; i < size; i++) {
    cout << "Subject ID: " << arr[i].ID << endl;
    cout << "Subject Name: " << arr[i].name << endl;
    cout << endl;
  }
}

// displaying center in a list
void DisplayCenter() {
  vector<Center> arr = _CENTER;
  size_t size = arr.size();
  cout << "List of Center's Information" << endl;
  for (size_t i = 0; i < size; i++) {
    cout << "Center ID: " << arr[i].ID << endl;
    cout << "Center Name: " << arr[i].name << endl;
    cout << endl;
  }
}

void SubDisplay(std::vector<Tutor *> &tutorV, size_t start, size_t end,
                bool isAdmin) {
  for (size_t i = start; i < end && i < tutorV.size(); i++) {
    cout << "Tutor ID: " << tutorV.at(i)->ID << endl;
    cout << "Tutor Name: " << tutorV.at(i)->name << endl;
    // if its not admin then only show
    // tutor id and name
    if (!isAdmin) {
      cout << endl;
      continue;
    }

    cout << "Pay Rate: " << tutorV.at(i)->payRate << endl;
    cout << "Rating: " << tutorV.at(i)->rating << endl;
    cout << "Phone Number: " << tutorV.at(i)->phone << endl;
    cout << "Address: " << tutorV.at(i)->address << endl;
    cout << "Joined Date: " << tutorV.at(i)->joinDate.ToString() << endl;
    cout << "Termination Date: " << tutorV.at(i)->terminateDate.ToString()
         << endl;
    cout << "Center ID: " << tutorV.at(i)->center->ID << endl;
    cout << "Center Name: " << tutorV.at(i)->center->name << endl;
    cout << "Subject ID: " << tutorV.at(i)->subject->ID << endl;
    cout << "Subject Name: " << tutorV.at(i)->subject->name << endl;
    cout << endl;
  }
}

void clearScreen() { system("cls || clear"); }
