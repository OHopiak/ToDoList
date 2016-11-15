#pragma once
#include "Task.h"

class User
{
public:
	//info:
	//	Constructor used to create new User
	User(string email, string login, string password);
	//info:
	//	Constructor used to parse data of existing User
	User(string data);
	~User();
	void addTask(string subject, string text);
	void removeTask(int position);
	void changeTaskDone(int position);
	void changeTaskText(int position, string text);
	void changeTaskSub(int position, string subject);
	//info:
	//	format: ~email~login~password~task1~task2~...~taskn~
	string to_string();

	string getEmail();
	string getLogin();
	string getPassword();
	vector<Task> & getTasks();

private:
	void parseText(string text);
	string email;
	string login;
	string password;
	vector<Task> tasks;
};

