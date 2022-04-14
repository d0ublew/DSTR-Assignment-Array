#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED


struct Date {
    int day, month, year;
    Date();
    Date(int day, int month, int year);
    ~Date();
};

#endif
