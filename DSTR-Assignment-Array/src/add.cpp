#include <iostream>
#include <string>
#include <vector>

#include "add.h"
#include "center.h"
#include "date.h"
#include "display.h"
#include "subject.h"
#include "tutor.h"
#include "validate.h"

// this method allows admin to insert new tutor information
Tutor *addingInterface(std::vector<Tutor *> &arr) {
  std::string date;
  Tutor *tutor = new Tutor();

  std::cout << "Please enter information below" << std::endl;
  while (true) {

    std::cout << "Tutor ID (TXX): ";
    std::getline(std::cin, tutor->ID);
    if (!isTutorIDFormatCorrect(tutor->ID)) {
      continue;
    }
    if (isTutorIDExisted(arr, tutor->ID)) {
      continue;
    }
    break;
  }

  std::cout << "Tutor Name: ";

  // use getline to get name with spaces
  std::getline(std::cin, tutor->name);

  while (true) {
    std::string setence = "Pay Rate (40 ~ 80): ";
    tutor->payRate = getFloatInput(setence);
    if (!isPayRateRangeValid(tutor->payRate)) {
      continue;
    }
    break;
  }

  tutor->rating = 0;
  tutor->countRate = 0;

  while (true) {
    std::cout << "Phone Number(10~11 digits): ";
    std::getline(std::cin, tutor->phone);

    if (!isPhoneFormatValid(tutor->phone)) {
      continue;
    }
    break;
  }

  std::cout << "Address: ";
  std::getline(std::cin, tutor->address);

  while (true) {

    std::cout << "Join Date (dd/MM/yyyy): ";
    std::getline(std::cin, date);

    if (!isDateValid(date)) {
      continue;
    }
    tutor->joinDate = date;
    break;
  }
  tutor->terminateDate = Date("-");

  while (true) {
    std::string ID;
    std::cout << "Please choose Center ID from list below" << std::endl;
    DisplayCenter();
    std::cout << "Center ID: ";
    std::getline(std::cin, ID);
    tutor->center = getCenterByID(_CENTER, ID);
    if (!(isCenterExisted(tutor->center))) {
      continue;
    }
    break;
  }

  while (true) {
    std::string ID;
    std::cout << "Please choose Subject ID from list below " << std::endl;
    DisplaySubject();
    std::cout << "Subject ID: ";
    std::getline(std::cin, ID);
    tutor->subject = getSubjectByID(_SUBJECT, ID);
    if (!(isSubjectExisted(tutor->subject))) {
      continue;
    }
    break;
  }

  return tutor;
}

// This method append the Tutor into the tutor vector to the back
void addToBack(std::vector<Tutor *> &arr, Tutor *tutor) {
  arr.push_back(tutor);
}

// This method insert the Tutor into the tutor vector to the front
void addToFront(std::vector<Tutor *> &arr, Tutor *tutor) {
  arr.insert(arr.begin(), tutor);
}
