#include <string>
#include <vector>

#include "student.h"

Student::Student() {
  username = "";
  password = "";
}

Student::Student(std::string paramUsername, std::string paramPassword) {
  username = paramUsername;
  password = paramPassword;
}
Student *getStudentByUsername(std::vector<Student> &studentV,
                              std::string username) {
  std::vector<Student>::iterator it;

  for (it = studentV.begin(); it != studentV.end(); it++) {
    Student s = *it;
    if (s.username == username) {
      return &(*it);
    }
  }
  return nullptr;
}
