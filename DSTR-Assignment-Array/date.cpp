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

std::string Date::ToString() {
    std::string strDate = "-";
    if (year != 0) {
        strDate = std::to_string(day) + '/' + std::to_string(month) + '/' +
                  std::to_string(year);
    }
    return strDate;
}
