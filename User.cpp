#include "User.h"


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
