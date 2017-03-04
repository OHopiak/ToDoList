#include "DataParser.h"
#include "NiceOut.h"

DataParser dp("data.dat");
User * me;


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

using namespace niceOut;

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
		printH("Welcome to the ToDoList application!");
		print("Choose option to be done:");
		print("\t1) Log in");
		print("\t2) Become a new user");
		print("\t3) Exit");
		printDS();
		int in;
		string instr;
		input("Option: ", instr);
		printE();
		inputToInt(instr, in);
		switch (in)
		{
		case 1:
			CLS;
			printH("Log In");
			input("Enter your login : ", login);
			input("Enter your password: ", password);
			printE();
			if (validateData(login) && validateData(password)) me = dp.getUser(login, password);
			CLS;
			if (!me) {
				alert("Login or password are incorrect!");
			}
			break;
		case 2:
			CLS;
			signUp();
			return;
		case 3:
			quit();
			CLS;
			break;
		default:
			CLS;
			alert("Wrong input, try again...");
			break;
		}
	}
}

//info:
//	Registration page gets user email, login and password
//	Checks if there already is the a user with this email or login
void signUp()
{
	string email, login, password;
	printH("Registration");
	input("\tEnter your email: ", email);
	input("\tEnter your login: ", login);
	if (!checkEmail(email) || dp.isInUsers(email, login)) {
		CLS;
		if (dp.isInUsers(email, login)) cout << "Account with this email or login already exists!\n\n";
		else cout << "You entered wrong format of email\n\n";
		auth();
		return;
	}
	input("\tEnter your password: ", password);
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
	printH("Hello " + me->getLogin() + "");
	print("Choose option to be done:");
	print("\t1) Create new task");
	print("\t2) Read undone tasks");
	print("\t3) Read done tasks");
	print("\t4) Exit");
	int in;
	string instr;
	input("Option: ", instr);
	printE();
	inputToInt(instr, in);
	switch (in)
	{
	case 1:
		CLS;
		addTask();
		break;
	case 2:
		CLS;
		readTasks();
		return;
	case 3:
		CLS;
		readTasks(false);
		break;
	case 4:
		quit();
		CLS;
		break;
	default:
		alert("Wrong input, try again...");
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
		string title = (undone ? "Undone" : "Done");
		title += " Task List";
		printH(title);
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
			string head = "\t" + to_string(i + 1) + ") Subject: " + task.getSubject() + "\t\t\tDate: " + task.getWasCreated();
			print(head);
			printDS();
			print(task.getText());
			printD();
		}
		if (undone) {
			print("Choose option to be done:");
			print("\t1) Edit a task");
			print("\t2) Delete a task");
			print("\t3) Make task done");
			print("\t4) Finish reading");
			int in;
			string instr;
			input("Option: ", instr);
			printE();
			inputToInt(instr, in);
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
				alert("Wrong input, try again...");
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
				alert("Wrong input, try again...");
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
	printH("New Task");
	input("Enter the subject: ", subject);
	printDS();
	print("Enter the text:[write q to exit]");
	text = "";
	string line = "";
	while (line != "q") {
		text += line;
		cout << hvm << " ";
		cin >> line;
		if (line != "q") text += "\n";
	}
	validateData(subject);
	validateData(text);
	int pos;
	while ((pos = text.find('\n')) == 0 || (pos = text.find('\n')) == text.size() - 1) {
		if (pos == 0)
		{
			text = text.substr(1);
		}
		else if (pos == text.size())
		{
			text = text.substr(0, text.size() - 1);
		}
	}
	me->addTask(subject, text);
	CLS;
	alert("New task created!");
}

//info:
//	Edit existing Task
void editTask(vector<int> pos)
{
	int in;
	string instr;
	input("Which task to edit?[0 to escape]: ", instr);
	inputToInt(instr, in);
	if (in == 0) {
		CLS;
		return;
	}
	else if (in > 0 && in <= pos.size()) {
		CLS;
		string subject, text;
		printH("Editing Task");
		Task & task = me->getTasks()[pos[in - 1]];
		string head = "\t" + to_string(in + 1) + ") Subject: " + task.getSubject() + "\t\t\tDate: " + task.getWasCreated();
		print(head);
		printDS();
		print(task.getText());
		printD();
		input("Enter the subject: ", subject);
		printDS();
		print("Enter the text:[write q to exit] ");
		text = "";
		string line = "";
		while (line != "q") {
			text += line;
			cout << hvm << " ";
			cin >> line;
			if (line != "q") text += "\n";
		}
		int pos;
		while ((pos = text.find('\n')) == 0 || (pos = text.find('\n')) == text.size() - 1) {
			if (pos == 0)
			{
				text = text.substr(1);
			}
			else if (pos == text.size())
			{
				text = text.substr(0, text.size() - 1);
			}
		}

		task = Task(subject, text);
		CLS;
		alert("Successfully edited");
	}
	else {
		CLS;
		alert("Wrong input");
	}
}

//info:
//	Delete existing Task
void deleteTask(vector<int> pos)
{
	int in;
	string instr;
	input("Which task to delete?[0 to escape]: ", instr);
	inputToInt(instr, in);
	if (in == 0) return;
	else if (in > 0 && in <= pos.size()) {
		me->removeTask(pos[in - 1]);
		alert("Successfully deleted!");
	}
	else {
		CLS;
		alert("Wrong input!");
	}
}

//info:
//	Change done state of existing Task
void changeDone(vector<int> pos)
{
	int in;
	string instr;
	input("Done state of which task to change?[0 to escape]: ", instr);
	inputToInt(instr, in);
	if (in == 0) return;
	else if (in > 0 && in <= pos.size()) {
		me->changeTaskDone(pos[in - 1]);
		CLS;
		alert("Successfully changed done state");
	}
	else {
		CLS;
		alert( "Wrong input");
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
	string instr;
	input("Do you really want to exit?[y/n]: ", instr);
	if (instr[0] == 'Y' || instr[0] == 'y') exit(0);
}
