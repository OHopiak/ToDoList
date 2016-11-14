#include "User.h"

void User::parseText(string text)
{
	delete email;
	delete login;
	delete password;
	delete tasks;
	tasks = new vector<Task>();
	int iter = 0, start = 1, end;
	for (size_t i = 1; i < text.size(); i++){
		if (text[i] == '~') {
		switch (iter++){
			case 0:
				end = i;
				email = new string(text, start, end - start);
				start = i + 1;
				break;
			case 1:
				end = i;
				login = new string(text, start, end - start);
				start = i + 1;
				break;
			case 2:
				end = i;
				password = new string(text, start, end - start);
				break;
			default:
				end = i;
				tasks->push_back(Task(string(text, start, end - start)));
				break;
			}
		}
	}
}

void User::addTask(string subject, string text)
{
	tasks->insert(tasks->begin(), Task(subject, text));
}

void User::removeTask(int position)
{
	tasks->erase(tasks->begin() + position);
}

void User::changeTaskDone(int position)
{
	tasks->at(position).changeDoneState();
}

void User::changeTaskText(int position, string text)
{
	tasks->at(position).setText(text);
}

void User::changeTaskSub(int position, string subject)
{
	tasks->at(position).setSubject(subject);
}

string User::getEmail()
{
	return *email;
}
string User::getLogin()
{
	return *login;
}
string User::getPassword()
{
	return *password;
}
const vector<Task>* User::getTasks()
{
	return tasks;
}

User::User(string email, string login, string password)
{
	this->email = &email;
	this->login = &login;
	this->password = &password;
}
User::~User()
{
	delete email;
	delete login;
	delete password;
	delete tasks;
}
