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
bool checkEmail(string email);
bool validateData(string & data);
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

//info:
//	init UI, login, sign up or exit
void auth()
{
	string login, password;
	while (!me) {
		bool wrongIn = false;
		cout << "\n\t\t\t\tWelcome to the ToDoList application!\n\n";
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
			if (validateData(login) && validateData(password)) me = dp.getUser(login, password); \
				if (!me) cout << "Login or password are incorrect!\n\n";
			break;
		case 2:
			CLS;
			signUp();
			return;
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

//info:
//	Registration page gets user email, login and password
//	Checks if there already is the a user with this email or login
void signUp()
{
	string email, login, password;
	cout << "Registration\n\n";
	cout << "\tEnter your email: ";
	cin >> email;
	cout << "\tEnter your login: ";
	cin >> login;
	if (!checkEmail(email) || dp.isInUsers(email, login)) {
		CLS;
		if (dp.isInUsers(email, login)) cout << "Account with this email or login already exists!\n\n";
		else cout << "You entered wrong format of email\n\n";
		auth();
		return;
	}
	cout << "\tEnter your password: ";
	cin >> password;
	if (validateData(login) && validateData(password) && validateData(email)) {
		dp.addUser(email, login, password);
		me = dp.getUser(login, password);
	}
	else {
		CLS;
		cout << "You entered wrong format of email, lofin or password (it cannot contain \'~\', \'^\' or\'|\')\n\n";
		auth();
		return;
	}
	CLS;
}

//info:
//	Main UI:
//	Create and Read tasks or Exit
void mainMenu()
{
	cout << ("\tHello " + me->getLogin() + "\n\n");
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
		CLS;
		break;
	case 2:
		readTasks();
		CLS;
		return;
	case 3:
		readTasks(false);
		CLS;
		break;
	case 4:
		quit();
		CLS;
		break;
	default:
		cout << "Wrong input, try again...\n\n";
		break;
	}
}

//info:
//	Read done or undone tasks
//	Edit (if undone), delete or change done state
void readTasks(bool undone)
{
	while (true) {
		CLS;
		vector<int> pos;
		cout << (undone ? "Undone" : "Done") << " Task List\n\n";
		for (size_t i = 0; i < me->getTasks().size(); i++)
		{
			Task & task = me->getTasks()[i];
			if (task.isDone() != undone) {
				pos.push_back(i);
			}
		}
		for (size_t i = 0; i < pos.size(); i++)
		{
			Task & task = me->getTasks()[pos[i]];
			cout << "\t" << (i + 1) << ") Subject: " << task.getSubject() << "\t\t\tDate: " << task.getWasCreated() << endl;
			cout << task.getText() << "\n\n";
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

//info:
//	Add new Task
void addTask()
{
	CLS;
	string subject, text;
	cout << "New Task\n\n";
	cout << "Enter the subject: ";
	cin >> subject;
	cout << "Enter the text:[write q to exit] \n";
	text = "";
	string line = "";
	int i = 0;
	while (line != "q") {
		text += line;
		getline(cin, line);
		i++;
		if (line != "q" && i != 0) text += "\n";
	}
	validateData(subject);
	validateData(text);
	me->addTask(subject, text);
	CLS;
	cout << "New task created!\n\n";
}

//info:
//	Edit existing Task
void editTask(vector<int> pos)
{
	int in;
	string input;
	cout << "Which task to edit?[0 to escape]: \n";
	cin >> input;
	inputToInt(input, in);
	if (in == 0) {
		CLS;
		return;
	}
	else if (in > 0 && in <= pos.size()) {
		CLS;
		string subject, text;
		cout << "Editing Task\n\n";
		Task & task = me->getTasks()[pos[in - 1]];
		cout << "\t" << (in + 1) << ") Subject: " << task.getSubject() << "\t\t\tDate: " << task.getWasCreated() << endl;
		cout << task.getText() << "\n\n";
		cout << "Enter the subject: ";
		cin >> subject;
		cout << "Enter the text:[write q to exit] ";
		text = "";
		string line = "";
		while (line != "q") {
			text += line;
			getline(cin, line);
			if (line != "q") text += "\n";
		}
		task = Task(subject, text);
		CLS;
		cout << "Successfully edited\n\n";
	}
	else {
		CLS;
		cout << "Wrong input\n\n";
	}
}

//info:
//	Delete existing Task
void deleteTask(vector<int> pos)
{
	int in;
	string input;
	cout << "Which task to delete?[0 to escape]: ";
	cin >> input;
	inputToInt(input, in);
	if (in == 0) return;
	else if (in > 0 && in <= pos.size()) {
		me->removeTask(pos[in - 1]);
		cout << "Successfully deleted\n\n";
	}
	else {
		CLS;
		cout << "Wrong input\n\n";
	}
}

//info:
//	Change done state of existing Task
void changeDone(vector<int> pos)
{
	int in;
	string input;
	cout << "Done state of which task to change?[0 to escape]: ";
	cin >> input;
	inputToInt(input, in);
	if (in == 0) return;
	else if (in > 0 && in <= pos.size()) {
		me->changeTaskDone(pos[in - 1]);
		cout << "Successfully changed done state\n\n";
	}
	else {
		CLS;
		cout << "Wrong input\n\n";
	}
}

//info:
//	Check if email is correct
bool checkEmail(string email)
{
	regex pattern("^[a-zA-Z0-9]+@[a-z]+\\.[a-z]+$");
	return regex_match(email, pattern);

}

//info:
//	Fixes errors with parsing
bool validateData(string & data)
{
	bool isValid = true;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] == '|' || data[i] == '~' || data[i] == '^') {
			data[i] = '_';
			isValid = false;
		}
	}
	return isValid;
}

//info:
//	Check if input is a number and set num the numeric value of input
//	(0 if input is wrong)
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

//info:
//	Check if user realy wants to exit
//	If he/she wants then shut down the app
void quit()
{
	string input;
	cout << "Do you really want to exit?[y/n]: ";
	cin >> input;
	if (input[0] == 'Y' || input[0] == 'y') exit(0);
}
