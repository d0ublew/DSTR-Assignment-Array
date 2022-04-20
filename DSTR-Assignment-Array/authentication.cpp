
#include "admin.h"
#include "file2struct.h"
#include "student.h"
#include "validate.h"
#include <iostream>
#include <string>
using namespace std;

std::hash<std::string> h;
const std::string ADMIN_FILE = "./data/admin.txt";
const std::string STUDENT_FILE = "./data/student.txt";

std::vector<Admin> _ADMIN = fileToAdmin(ADMIN_FILE);
std::vector<Student> _STUDENT = fileToStudent(STUDENT_FILE);

// Registering new Admin
void registerAdmin() {
    string password;
    Admin admin;
    cout << "Please insert information below" << endl;
    while (true) {

        cout << "Username: ";
        cin >> admin.username;
        if (isAdminUsernameExisted(_ADMIN, admin.username)) {
            continue;
        }
        cout << "Password: ";
        cin >> password;
        if (isSpaceExisted(password)) {
            cout << "Password cannot including space" << endl;
            continue;
        }
        admin.password = password;
        _ADMIN.push_back(admin);
        cout << "Register Succesful" << endl;
        adminToFile(_ADMIN, ADMIN_FILE);
        break;
    }
}

// Registering new student
void registerStudent() {
    string password;
    Student student;
    cout << "Please insert information below" << endl;
    while (true) {

        cout << "Username: ";
        cin >> student.username;
        if (isStudentUsernameExisted(_STUDENT, student.username)) {
            continue;
        }
        cout << "Password: ";
        cin >> password;
        if (isSpaceExisted(password)) {
            cout << "Password cannot including space" << endl;
            continue;
        }
        student.password = password;
        _STUDENT.push_back(student);
        cout << "Register Succesful" << endl;
        studentToFile(_STUDENT, STUDENT_FILE);
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
            cout << "Too many attemp, please try again" << endl;
            return false;
        }
        chance -= 1;
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        student = getStudentByUsername(_STUDENT, username);
        if (student == nullptr) {
            cout << "Username not found" << endl;
            continue;
        }

        if (password == student->password) {
            return true;
        } else {
            cout << "Invalid Password" << endl;
            continue;
        }
    }
}

// adminLogin
bool adminLogin() {
    Admin *admin;
    int chance = 3;
    string username;
    string password;
    while (true) {
        if (chance == 0) {
            cout << "Too many attemp, please try again" << endl;
            return false;
        }
        chance -= 1;
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        admin = getAdminByUsername(_ADMIN, username);
        if (admin == nullptr) {
            cout << "Username not found" << endl;
            continue;
        }

        if (password == admin->password) {
            return true;
        } else {
            cout << "Invalid Password" << endl;
            continue;
        }
    }
}

