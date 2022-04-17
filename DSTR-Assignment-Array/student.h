#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

struct Student {
    std::string username;
    size_t password;
    Student();
    Student(std::string paramUsername, std::string paramPassword);
};

Student* getStudentByUsername(std::vector<Student>& studentV, std::string username);

#endif
