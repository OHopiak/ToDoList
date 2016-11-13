#pragma once
#include "Task.h"

class User
{
public:
	User(string email, string login, string password);
	User(string login, string password);
	~User();
	void parseText(string text);
	void addTask(string subject, string text);
	void removeTask(int position);
	void changeTaskDone(int position);
	void changeTaskText(int position, string text);
	void changeTaskSub(int position, string subject);

	string getEmail();
	string getLogin();
	string getPassword();
	const vector<Task> * getTasks();


private:
	string * email;
	string * login;
	string * password;
	vector<Task> * tasks;
};

