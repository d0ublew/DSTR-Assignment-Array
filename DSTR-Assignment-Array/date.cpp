#include "date.h"

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::~Date() {
}

Date::Date(int paramDay, int paramMonth, int paramYear) {
    day = paramDay;
    month = paramMonth;
    year = paramYear;
}
