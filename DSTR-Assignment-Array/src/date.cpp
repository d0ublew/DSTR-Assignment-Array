#pragma warning(push)
#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "date.h"
#include "file2struct.h"

Date::Date() {
  day = 0;
  month = 0;
  year = 0;
}

Date::~Date() {}

Date::Date(int paramDay, int paramMonth, int paramYear) {
  day = paramDay;
  month = paramMonth;
  year = paramYear;
}

Date::Date(std::string strDate) {
  day = 0;
  month = 0;
  year = 0;
  if (strDate == "-") {
    return;
  }
  std::vector<std::string> date = splitString(strDate, "/");
  day = std::stoi(date[0]);
  month = std::stoi(date[1]);
  year = std::stoi(date[2]);
}

bool Date::Empty() {
  if (day == 0 || month == 0 || year == 0)
    return true;
  return false;
}

std::string Date::ToString() {
  std::string strDate = "-";
  if (year != 0) {
    strDate = std::to_string(day) + '/' + std::to_string(month) + '/' +
              std::to_string(year);
  }
  return strDate;
}

void Date::Today() {
  time_t now = time(0);
  tm *t = localtime(&now);
  day = t->tm_mday;
  month = 1 + t->tm_mon;
  year = 1900 + t->tm_year;
}

Date Date::SixMonthBack() {
  Date sixMonth = Date(*this);
  if (sixMonth.month > 6) {
    sixMonth.month -= 6;
  } else {
    sixMonth.year -= 1;
    sixMonth.month += 6;
  }
  return sixMonth;
}

bool Date::operator<(const Date &d) {
  if (this->year < d.year)
    return true;
  else if (this->year > d.year)
    return false;
  else if (this->month < d.month)
    return true;
  else if (this->month > d.month)
    return false;
  else if (this->day < d.day)
    return true;
  return false;
}

bool Date::operator>(const Date &d) {
  if (this->year < d.year)
    return false;
  else if (this->year > d.year)
    return true;
  else if (this->month < d.month)
    return false;
  else if (this->month > d.month)
    return true;
  else if (this->day > d.day)
    return true;
  return false;
}

bool Date::operator==(const Date &d) {
  if (this->year == d.year && this->month == d.month && this->day == d.day) {
    return true;
  }
  return false;
}

#pragma warning(pop)
