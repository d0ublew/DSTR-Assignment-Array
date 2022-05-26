#include <iostream>
#include <vector>

#include "date.h"
#include "delete.h"
#include "display.h"
#include "tutor.h"
#include "validate.h"

void DeleteTutor(std::vector<Tutor *> &tutorV, std::string ID) {
  std::vector<Tutor *>::iterator it = tutorV.begin();

  while (it != tutorV.end() && (*it)->ID != ID) {
    it++;
  }

  if (it == tutorV.end()) {
    std::cout << "No matching record found.\n";
    Enter();
    return;
  }

  while (true) {
    {
      std::vector<Tutor *> temp(it, it + 1);
      clearScreen();
      SubDisplay(temp, 0, 1, true);
    }
    int choice = getIntInput("Do you want to proceed? (1 = Yes / 0 = No): ");
    if (!isChoiceInMenuRange(choice, 1))
      continue;
    if (choice == 1) {
      tutorV.erase(it);
      std::cout << "Delete successful\n";
      Enter();
      return;
    } else if (choice == 0) {
      return;
    }
  }
}

void DeleteTerminatedTutor(std::vector<Tutor *> &tutorV) {
  Date today = Date();
  today.Today();
  Date sixMonth = today.SixMonthBack();

  /**
   * Create array to store the index of tutor which can be deleted in
   * descending order, such that the deletion is performed from the end
   * to not mess with the other index
   */
  std::vector<size_t> idx;

  puts("");
  for (size_t i = 0; i < tutorV.size(); i++) {
    Date term = tutorV.at(i)->terminateDate;
    if (!term.Empty() && term < sixMonth) {
      idx.insert(idx.begin(), i);
      SubDisplay(tutorV, 0, 1, true);
    }
  }

  if (idx.size() == 0) {
    std::cout << "No tutor to be deleted.\n";
    Enter();
    return;
  }

  while (true) {
    int choice = getIntInput(
        "These tutors will be deleted, proceed? (1 = Yes / 0 = No): ");
    if (!isChoiceInMenuRange(choice, 1))
      continue;
    if (choice == 1) {
      // delete tutor starting from the end to the start
      for (size_t i = 0; i < idx.size(); i++) {
        // deallocate memory
        delete tutorV.at(idx.at(i));
        tutorV.erase(tutorV.begin() + idx.at(i));
      }
      std::cout << "Delete successful\n";
      Enter();
      return;
    } else if (choice == 0) {
      return;
    }
  }
}
