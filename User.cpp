#include "User.h"


User::User(string email, string login, string password)
{
	this->email = &email;
	this->login = &login;
	this->password = &password;
}

User::User(string textToParse)
{
	parseText(textToParse);
}

User::~User()
{
	delete tasks;
}

void User::parseText(string text)
{
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
