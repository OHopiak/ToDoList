#include "Header.h"
#include "DataParser.h"
using namespace std;

DataParser dp("E:\\Education\\Programming\\C++\\ToDoList\\res\\new.txt");
User * me;
vector<Task> * tasks;

void auth();
void signUp();
void mainMenu();
void readTasks(bool undone = true);
void addTask();
void editTask(vector<int> pos);
void deleteTask(vector<int> pos);
void changeDone(vector<int> pos);
bool checkData(string email);
void inputToInt(string input, int & num);
void quit();

int main() {
	CLS;
	auth();
	while (true) {
		mainMenu();
	}
	return 0;
}

void auth()
{
	string login, password;
	while (!me) {
		bool wrongIn = false;
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
			if (!me) cout << "Login or password are incorrect!\n\n";
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
			cout << "Wrong input, try again...\n\n";
			break;
		}
		CLS;
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

void mainMenu()
{
	cout << ("\tHello " + me->getLogin()) << "\n\n";
	cout << "Choose option to be done:" << endl;
	cout << "\t1) Create new task" << endl;
	cout << "\t2) Read undone tasks" << endl;
	cout << "\t3) Read done tasks" << endl;
	cout << "\t4) Exit" << endl;
	int in;
	string input;
	cout << "Option: ";
	cin >> input;
	inputToInt(input, in);
	switch (in)
	{
	case 1:
		CLS;
		addTask();
		break;
	case 2:
		readTasks();
		return;
		break;
	case 3:
		readTasks(false);
		break;
	case 4:
		quit();
		break; 
	default:
		cout << "Wrong input, try again...\n\n";
		break;
	}
}

void readTasks(bool undone)
{
	while (true) {
		CLS;
		vector<int> pos;
		cout << (undone ? "Undone" : "Done") << " Task List\n\n";
		for (size_t i = 0; i < me->getTasks().size(); i++)
		{
			pos.push_back(i);
		}
		for (size_t i = 0; i < pos.size(); i++)
		{
			Task & task = me->getTasks()[pos[i]];
			if (task.isDone() != undone) {
				cout << "\t" << (i + 1) << ") Subject: " << task.getSubject() << "\t\t\tDate: " << task.getWasCreated() << endl;
				cout << task.getText() << "\n\n";
			}
		}
		if (undone) {
			cout << "Choose option to be done:" << endl;
			cout << "\t1) Edit a task" << endl;
			cout << "\t2) Delete a task" << endl;
			cout << "\t3) Make task done" << endl;
			cout << "\t4) Finish reading" << endl;
			int in;
			string input;
			cout << "Option: ";
			cin >> input;
			inputToInt(input, in);
			switch (in)
			{
			case 1:
				editTask(pos);
				break;
			case 2:
				deleteTask(pos);
				return;
				break;
			case 3:
				changeDone(pos);
				break;
			case 4:
				CLS;
				return;
			default:
				cout << "Wrong input, try again...\n\n";
				break;
			}
		}
		else {
			cout << "Choose option to be done:" << endl;
			cout << "\t1) Delete a task" << endl;
			cout << "\t2) Make task undone" << endl;
			cout << "\t3) Finish reading" << endl;
			int in;
			string input;
			cout << "Option: ";
			cin >> input;
			inputToInt(input, in);
			switch (in)
			{
			case 1:
				deleteTask(pos);
				break;
			case 2:
				changeDone(pos);
				return;
				break;
			case 3:
				CLS;
				return;
			default:
				cout << "Wrong input, try again...\n\n";
				break;
			}
		}
	}
}

void addTask()
{
	CLS;
	string subject, text;
	cout << "New Task\n\n";
	cout << "Enter the subject: ";
	cin >> subject;
	cout << "Enter the text: ";
	cin >> text;
	me->addTask(subject, text);
}

void editTask(vector<int> pos)
{
}

void deleteTask(vector<int> pos)
{
}

void changeDone(vector<int> pos)
{
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
