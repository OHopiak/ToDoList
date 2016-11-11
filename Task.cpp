#include "Task.h"


void Task::parseText(string text)
{
}

void Task::changeDoneState()
{
	isDone = !isDone;
}

string Task::to_string()
{
	return "Hi nigga\n";
}

string Task::getWasCreated()
{
	return *wasCreated;
}
string Task::getSubject()
{
	return *subject;
}
void Task::setSubject(string subject)
{
	this->subject = &subject;
}
string Task::getText()
{
	return *text;
}
void Task::setText(string text)
{
}

Task::Task(string textToParse)
{
	parseText(textToParse);
	isDone = false;
}
Task::~Task()
{
	delete wasCreated;
	delete subject;
	delete text;
}
