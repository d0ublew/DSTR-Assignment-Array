
#include <iostream>
#include <string>
#include "admin.h"
#include "student.h"
#include "file2struct.h"
#include "validate.h"
using namespace std;

std::hash<std::string> h;
const std::string ADMIN_FILE = "./data/admin.txt";
const std::string STUDENT_FILE = "./data/student.txt";

std::vector<Admin> _ADMIN = fileToAdmin(ADMIN_FILE);
std::vector<Student> _STUDENT = fileToStudent(STUDENT_FILE);


void registerAdmin()
{
	string password;
	Admin admin;
	cout << "Please insert information below" << endl;
	while (true)
	{
		
		cout << "Username: ";
		cin >> admin.username;
		if (isAdminUsernameExisted(_ADMIN, admin.username)) { continue; }
		cout << "Password: ";
		cin >> password;
		if (isSpaceExisted(password))
		{
			cout << "Password cannot including space" << endl;
			continue;
		}
		admin.password = password;
		_ADMIN.push_back(admin);
		cout << "Register Succesful"<<endl;
		adminToFile(_ADMIN,ADMIN_FILE);
		break;
	}
	

}

void registerStudent()
{
	string password;
	Student student;
	cout << "Please insert information below" << endl;
	while (true)
	{

		cout << "Username: ";
		cin >> student.username;
		if (isStudentUsernameExisted(_STUDENT, student.username)) { continue; }
		cout << "Password: ";
		cin >> password;
		if (isSpaceExisted(password))
		{
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

//bool studentLogin()
//{
//
//}

bool adminLogin()//default admin abcd1234
{
	int chance = 3;
	string username;
	string password;
	while (true)
	{
		if (chance == 0) 
		{
			cout << "Too many attemp, please try again" << endl;
			return false;
		}
		chance -= 1;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		if (username == "admin" && password == "abc")
		{
			return true;
		}
		else
		{
			cout << "Invalid Password" << endl;
			continue;
		}
		
	}

}




