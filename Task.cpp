#include "Task.h"

void Task::parseText(string text)
{
	delete subject;
	delete this->text;
	delete wasCreated;
	int iter = 0, start = 1, end;
	for (size_t i = 1; i < text.size(); i++)
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

string Task::dateNow()
{
	time_t t = time(0);   // get time now
	struct tm * now = new tm();
	localtime_s(now, &t);
	string date = "";
	date += std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_mon + 1) + "/" + std::to_string(now->tm_year + 1900);
	delete now;
	return date;
}

void Task::changeDoneState()
{
	done = !done;
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

bool Task::isDone()
{
	return done;
}
void Task::setDone(bool done)
{
	this->done = done;
}

Task::Task(string textToParse)
{
	parseText(textToParse);
	done = false;
}
Task::Task(string subject, string text)
{
	string data = "|" + subject + "|" + text + "|" + dateNow() + "|";
	parseText(data);
	done = false;
}
Task::~Task()
{
	delete wasCreated;
	delete subject;
	delete text;
}
