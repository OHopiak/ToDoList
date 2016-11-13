#include "User.h"

void User::parseText(string text)
{

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
