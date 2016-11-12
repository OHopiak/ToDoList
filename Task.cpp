#include "Task.h"

void Task::parseText(string text)
{
	/*
		sub{
		
		}sub//text{

		}text//done{
		
		}done//date{

		}date
	*/
	regex rgx("****(.+)****");
	smatch match;

	if (regex_search(text, match, rgx))
	{	
		cout << " f ";
		for (auto m : match)  cout << m << '\n';
	}
	*subject = "Title";
	*(this->text) = "text";
	*wasCreated = "now";
}

void Task::changeDoneState()
{
	isDone = !isDone;
}

string Task::to_string()
{
	return "subject: " + *subject + "\ttext: " + *text + "\tdate" + *wasCreated;
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
