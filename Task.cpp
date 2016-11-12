#include "Task.h"

void Task::parseText(string text)
{
	delete subject;
	delete this->text;
	delete wasCreated;
	int iter = 0, start = 0, end;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i] == '|') {
			switch (iter++)
			{
			case 0:
				end = i;
				subject = new string(text, start, end - start);
				start = i + 1;
				break;
			case 1:
				end = i;
				this->text = new string(text, start, end - start);
				start = i + 1;
				break;
			case 2:
				end = text.size() - 1;
				wasCreated = new string(text, start, end - start);
				break;
			default:
				break;
			}
		}
	}
}

void Task::changeDoneState()
{
	isDone = !isDone;
}

string Task::to_string()
{
	return "subject: \"" + *subject + "\", text: \"" + *text + "\", date: " + *wasCreated;
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
	this->text = &text;

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
