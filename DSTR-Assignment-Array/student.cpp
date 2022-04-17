#include <string>
#include "student.h"

Student::Student() {
    username = "";
    password = 0;
}

Student::Student(std::string paramUsername, std::string paramPassword) {
    std::hash<std::string> h;
    username = paramUsername;
    password = h(paramPassword);
}
