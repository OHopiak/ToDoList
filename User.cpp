#include "User.h"

void User::parseText(string text)
{
	int iter = 0, start = 1, end;
	for (size_t i = 1; i < text.size(); i++){
		if (text[i] == '~') {
		switch (iter++){
			case 0:
				end = i;
				email = string(text, start, end - start);
				start = i + 1;
				break;
			case 1:
				end = i;
				login = string(text, start, end - start);
				start = i + 1;
				break;
			case 2:
				end = i;
				password = string(text, start, end - start);
				start = i + 1;
				break;
			default:
				end = i;
				Task temp = Task(string(text, start, end - start));
				tasks.push_back(temp);
				start = i + 1;
				break;
			}
		}
	}
}

void User::addTask(string subject, string text)
{
	tasks.insert(tasks.begin(), Task(subject, text));
}

void User::removeTask(int position)
{
	tasks.erase(tasks.begin() + position);
}

void User::changeTaskDone(int position)
{
	tasks.at(position).changeDoneState();
}

void User::changeTaskText(int position, string text)
{
	tasks.at(position).setText(text);
}

void User::changeTaskSub(int position, string subject)
{
	tasks.at(position).setSubject(subject);
}

string User::getEmail()
{
	return email;
}
string User::getLogin()
{
	return login;
}
string User::getPassword()
{
	return password;
}
vector<Task> & User::getTasks()
{
	return tasks;
}

string User::to_string()
{
	string data = "~";
	data += email + "~";
	data += login + "~";
	data += password + "~";
	for (size_t i = 0; i < tasks.size(); i++) {
		Task task = tasks[i];
		data += task.to_string() + "~";
	}
	return data;
}

User::User(string email, string login, string password)
{
	this->email = string(email);
	this->login = string(login);
	this->password = string(password);
	tasks = vector<Task>();
}
User::User(string data)
{
	tasks = vector<Task>();
	parseText(data);
}
User::~User()
{
}
