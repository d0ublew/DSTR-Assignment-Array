#include <iostream>
#include <string>

#include "add.h"
#include "admin_menu.h"
#include "authentication.h"
#include "delete.h"
#include "display.h"
#include "file2struct.h"
#include "modify.h"
#include "search.h"
#include "sort.h"
#include "student_menu.h"
#include "tutor.h"
#include "validate.h"

void startMenu(std::vector<Tutor *> &tutorV) {
  while (true) {
    clearScreen();
    std::cout << "Welcome to eXcel Tuition Centre" << std::endl;
    std::cout << "Who are you?" << std::endl;
    std::cout << "1) Admin" << std::endl;
    std::cout << "2) Student" << std::endl;
    std::cout << "3) Student Register" << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 3))
      continue;
    // code here
    switch (choice) {
    case 0:
      std::cout << "Thank you for using this system" << std::endl;
      return;

    case 1:
      if (adminLogin()) {
        adminMainMenu(tutorV);
      } else {
        continue;
      }
      break;
    case 2:
      if (studentLogin()) {
        studentRatingMenu(tutorV);
      } else {
        continue;
      }
      break;
    case 3:
      registerStudent();
      break;
    }
  }
}
void modifyMenu(std::vector<Tutor *> &tutorV) {
  while (true) {
    clearScreen();
    std::cout << "You are About to Modify Tutor Record, Please Becareful!\n";
    std::cout << "1)Modify by Tutor ID" << std::endl;
    std::cout << "0)Return to Previous Page" << std::endl;
    std::string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 1))
      continue;
    Tutor query;
    int (*CompareFn)(Tutor &, Tutor &) = nullptr;
    if (choice == 1) {
      std::cout << "Enter Tutor ID (TXX): ";
      std::getline(std::cin, query.ID);
      CompareFn = &CompareTutorID;
      std::vector<Tutor *> result = searchTutor(tutorV, query, (*CompareFn));
      if (result.size() != 0) {
        modifyTutor(result);
        tutorToFile(tutorV, TUTOR_FILE);
      } else {
        std::cout << "No Tutor Found please try another Tutor ID"
                        << std::endl;
        Enter();
      }
    } else if (choice == 0) {
      return;
    }
  }
}
void adminMainMenu(std::vector<Tutor *> &tutorV) {
  while (true) {
    clearScreen();
    std::cout << "Welcome back admin, please select a function"
                    << std::endl;
    std::cout << "1) Add Tutor" << std::endl;
    std::cout << "2) Display Tutor" << std::endl;
    std::cout << "3) Sort Tutor" << std::endl;
    std::cout << "4) Search Tutor" << std::endl;
    std::cout << "5) Modify Tutor" << std::endl;
    std::cout << "6) Termination or Delete Tutor" << std::endl;
    std::cout << "7) Register New Admin" << std::endl;
    std::cout << "0) Logout" << std::endl;
    std::string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 7))
      continue;
    switch (choice) {
    case 0:
      return;

    case 1:
      addMenu(tutorV);
      break;
    case 2:
      DisplayTutor(tutorV);
      break;
    case 3:
      sortMenu(tutorV);
      break;
    case 4:
      searchMenu(tutorV);
      break;
    case 5:
      modifyMenu(tutorV);
      break;
    case 6:
      deleteMenu(tutorV);
      break;
    case 7:
      registerAdmin();
      break;
    }
  }
}

void addMenu(std::vector<Tutor *> &tutorV) {

  while (true) {
    clearScreen();
    Tutor *tutor;
    std::cout << "Where you want to add?" << std::endl;
    std::cout << "1) Add to First" << std::endl;
    std::cout << "2) Add to Last" << std::endl;
    std::cout << "0) Previous Page" << std::endl;
    std::string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 2))
      continue;
    // code here
    switch (choice) {
    case 0:
      return;

    case 1:
      // code here
      tutor = addingInterface(tutorV);
      addToFront(tutorV, tutor);
      tutorToFile(tutorV, TUTOR_FILE);
      std::cout << "Tutor Added to Front Succesfully!\n";
      Enter();
      break;
    case 2:
      // code here
      tutor = addingInterface(tutorV);
      addToBack(tutorV, tutor);
      tutorToFile(tutorV, TUTOR_FILE);
      std::cout << "Tutor Added to Back Succesfully!\n";
      Enter();
      break;
    }
  }
}

void sortMenu(std::vector<Tutor *> &tutorV) {
  while (true) {
    clearScreen();
    std::cout << "How do you want to sort?" << std::endl;
    std::cout << "1) Sort by Tutors ID" << std::endl;
    std::cout << "2) Sort by Pay Rate " << std::endl;
    std::cout << "3) Sort by Overall Performance" << std::endl;
    std::cout << "0) Previous Page" << std::endl;
    std::string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 3))
      continue;
    int (*CompareFn)(Tutor &, Tutor &) = nullptr;
    switch (choice) {
    case 1:
      CompareFn = &CompareTutorID;
      break;
    case 2:
      CompareFn = &CompareTutorPay;
      break;
    case 3:
      CompareFn = &CompareTutorRating;
      break;
    case 0:
      return;
    }
    std::cout << "Sort in:\n";
    std::cout << "1) Ascending order\n";
    std::cout << "2) Descending order\n";
    std::cout << "0) Back\n";
    bool valid = false;
    while (!valid) {
      int option = getIntInput("Enter your choice: ");
      if (isChoiceInMenuRange(option, 2)) {
        valid = true;
        char order = ' ';
        if (option == 0) {
          break;
        } else if (option == 1) {
          order = 'a';
        } else if (option == 2) {
          order = 'd';
        }
        std::vector<Tutor *> sortedTutorV =
            sortTutor(tutorV, (*CompareFn), order);
        DisplayTutor(sortedTutorV);
      }
    }
  }
}

void searchMenu(std::vector<Tutor *> &tutorV) {
  while (true) {
    clearScreen();
    std::cout << "How do you want to search?" << std::endl;
    std::cout << "1) Search by Tutor ID" << std::endl;
    std::cout << "2) Search by overall performance" << std::endl;
    std::cout << "0) Previous Page" << std::endl;
    int choice = getIntInput("Enter your choice: ");
    if (!isChoiceInMenuRange(choice, 2))
      continue;
    Tutor query;
    int (*CompareFn)(Tutor &, Tutor &) = nullptr;
    if (choice == 0) {
      break;
    } else if (choice == 1) {
      std::cout << "Enter Tutor ID (TXX): ";
      std::getline(std::cin, query.ID);
      CompareFn = &CompareTutorID;
    } else if (choice == 2) {
      query.rating = getFloatInput("Enter Tutor rating: ");
      CompareFn = &CompareTutorRating;
    }
    std::vector<Tutor *> result = searchTutor(tutorV, query, (*CompareFn));
    DisplayTutor(result);
  }
}

void deleteMenu(std::vector<Tutor *> &tutorV) {
  while (true) {
    clearScreen();
    std::cout << "Which function you need?" << std::endl;
    std::cout << "1) Terminate all expired tutors" << std::endl;
    std::cout << "2) Delete specific tutor data" << std::endl;
    std::cout << "0) Previous Page" << std::endl;
    std::string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 2))
      continue;
    // code here
    if (choice == 1) {
      DeleteTerminatedTutor(tutorV);
      tutorToFile(tutorV, TUTOR_FILE);
    }

    else if (choice == 2) {
      std::string ID;
      std::cout << "Enter Tutor ID (TXX): ";
      std::getline(std::cin, ID);
      DeleteTutor(tutorV, ID);
      tutorToFile(tutorV, TUTOR_FILE);
    } else if (choice == 0) {
      return;
    }
  }
}
