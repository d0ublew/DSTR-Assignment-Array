#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>

struct Student {
    std::string username;
    size_t password;
    Student();
    Student(std::string paramUsername, std::string paramPassword);
};

#endif
