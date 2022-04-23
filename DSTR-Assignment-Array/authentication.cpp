#include "authentication.h"
#include "admin.h"
#include "file2struct.h"
#include "student.h"
#include "validate.h"
#include <iostream>
#include <string>
using namespace std;

const std::string ADMIN_FILE = "./admin.txt";
const std::string STUDENT_FILE = "./student.txt";

std::vector<Admin> _ADMIN = fileToAdmin(ADMIN_FILE);
std::vector<Student> _STUDENT = fileToStudent(STUDENT_FILE);

// Registering new Admin
void registerAdmin() {
    Admin admin;
    cout << "Please insert information below" << endl;
    while (true) {

        cout << "Username: ";
        getline(cin, admin.username);
        if (isAdminUsernameExisted(_ADMIN, admin.username)) {
            cout << "Username is already in use\n";
            continue;
        }
        cout << "Password: ";
        getline(cin, admin.password);
        if (isSpaceExisted(admin.password)) {
            cout << "Password cannot contain space(s)" << endl;
            continue;
        }
        _ADMIN.push_back(admin);
        adminToFile(_ADMIN, ADMIN_FILE);
        cout << "Register Succesful" << endl;
        break;
    }
}

// Registering new student
void registerStudent() {
    Student student;
    cout << "Please insert information below" << endl;
    while (true) {

        cout << "Username: ";
        getline(cin, student.username);
        if (isStudentUsernameExisted(_STUDENT, student.username)) {
            cout << "Username is already in use\n";
            continue;
        }
        cout << "Password: ";
        getline(cin, student.password);
        if (isSpaceExisted(student.password)) {
            cout << "Password cannot contain space(s)" << endl;
            continue;
        }
        _STUDENT.push_back(student);
        studentToFile(_STUDENT, STUDENT_FILE);
        cout << "Register Succesful" << endl;
        break;
    }
}

// Student Login
bool studentLogin() {
    Student *student;
    int chance = 3;
    string username;
    string password;
    while (true) {
        if (chance == 0) {
            cout << "Too many attempt, please try again" << endl;
            return false;
        }
        chance -= 1;
        cout << "Username: ";
        getline(cin, username);

        cout << "Password: ";
        getline(cin, password);

        student = getStudentByUsername(_STUDENT, username);
        if (student != nullptr && password == student->password) {
            return true;
        }

        cout << "Invalid credentials" << endl;
    }
}

// adminLogin
bool adminLogin() {
    if (_ADMIN.size() == 0) {
        initAdmin();
        _ADMIN = fileToAdmin(ADMIN_FILE);
    }
    Admin *admin;
    int chance = 3;
    string username;
    string password;
    while (true) {
        if (chance == 0) {
            cout << "Too many attempt, please try again" << endl;
            return false;
        }
        chance -= 1;
        cout << "Username: ";
        getline(cin, username);

        cout << "Password: ";
        getline(cin, password);

        admin = getAdminByUsername(_ADMIN, username);
        if (admin != nullptr && password == admin->password) {
            return true;
        }

        cout << "Invalid credentials" << endl;
    }
}

