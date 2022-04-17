#include <string>
#include <vector>
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
Student* getStudentByUsername(std::vector<Student>& studentV, std::string username) {
    std::vector<Student>::iterator it;

    for (it = studentV.begin(); it != studentV.end(); it++) {
        Student s = *it;
        if (s.username == username) {
            return &(*it);
        }
    }
    return nullptr;
}
