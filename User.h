#pragma once
#include "Task.h"

class User
{
public:
	User(string email, string login, string password);
	User(string textToParse);
	~User();
	void parseText(string text);
	string getEmail();
	string getLogin();
	string getPassword();

private:
	string * email;
	string * login;
	string * password;
	vector<Task> * undoneTasks;
	vector<Task> * udoneTasks;
};

