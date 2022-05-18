#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>

struct Date {
  int day, month, year;
  Date();
  Date(std::string);
  Date(int day, int month, int year);
  ~Date();
  std::string ToString();
  bool Empty();
  void Today();
  Date SixMonthBack();
  bool operator<(const Date &);
  bool operator>(const Date &);
  bool operator==(const Date &);
};

#endif
