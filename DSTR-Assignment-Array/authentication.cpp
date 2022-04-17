
#include <iostream>
#include <string>
using namespace std;



bool adminLogin()
{

	string username;
	string password;
	while (true)
	{
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




