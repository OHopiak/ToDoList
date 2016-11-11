#pragma once
#include "Task.h"

class User
{
public:
	User(string textToParse);
	~User();
	void parseText(string text);

private:
	string email;
	string login;
	string password;
	vector<Task> * tasks;
};

