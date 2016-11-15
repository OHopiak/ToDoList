#include "Header.h"
#include "DataParser.h"
using namespace std;

DataParser dp("E:\\Education\\Programming\\C++\\ToDoList\\res\\new.txt");
User * me;
void init();
void auth();
void signUp();
void readTasks();
void addTask();
void editTask();
void deleteTask();
void changeDone();
bool checkData(string email);
void inputToInt(string input, int & num);
void quit();

int main() {
	init();
	auth();
	cout << me->to_string() << endl;
	system("pause");
	return 0;
}

void init()
{
	CLS;
}

void auth()
{
	string login, password;
	while (!me) {
		cout << "Choose option to be done:" << endl;
		cout << "\t1) Log in" << endl;
		cout << "\t2) Become a new user" << endl;
		cout << "\t3) Exit" << endl;
		int in;
		string input;
		cout << "Option: ";
		cin >> input;
		inputToInt(input, in);
		switch (in)
		{
		case 1:
			CLS;
			cout << "Log In\n\n";
			cout << "Enter your login: ";
			cin >> login;
			cout << "Enter your password: ";
			cin >> password;
			me = dp.getUser(login, password);
			break;
		case 2:
			CLS;
			signUp();
			return;
			break;
		case 3:
			quit();
			break;
		default:
			break;
		}
		CLS;
		if(!me) cout << "Login or password are incorrect!\n\n";
	}
}

void signUp()
{
	string email, login, password;
	cout << "Registration\n\n";
	cout << "\tEnter your email: ";
	cin >> email;
	if (!checkData(email)) {
		CLS;
		cout << "Account with this email already exists!\n\n";
		signUp();
		return;
	}
	cout << "\tEnter your login: ";
	cin >> login;
	cout << "\tEnter your password: ";
	cin >> password;
	dp.addUser(email, login, password);
	me = dp.getUser(login, password);
}

bool checkData(string email)
{
	regex pattern("^[a-zA-Z0-9]+@[a-z]+\\.[a-z]+$");
	return regex_match(email, pattern) && !dp.isInUsers(email);

}

void inputToInt(string input, int & num)
{
	regex pattern("^[1-9][0-9]*$");
	if (regex_match(input, pattern)) {
		num = stoi(input);
	}
	else {
		num = 0;
	}
}

void quit()
{
	string input;
	cout << "Do you really want to exit?[y/n]: ";
	cin >> input;
	if (input[0] == 'Y' || input[0] == 'y') exit(0);
}
