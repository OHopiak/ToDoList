#pragma once
#include <ctime>
#include "Header.h"
using namespace std;
class Task
{
public:
	//info:
	//	Constructor that takes text with data and restores existing task
	Task(string textToParse);
	//info:
	//	Constructor that creates new task
	Task(string subject, string text);
	~Task();
	//info:
	//	Parse text with subject, text and date of creation to field values
	string dateNow();
	void changeDoneState();
	//info:
	//	subject: "[subject]", text: "[text]", date[autogenerated date]:
	string to_string();
	string getWasCreated();
	string getSubject();
	void setSubject(string subject);
	string getText();
	void setText(string text);
	bool isDone();
	void setDone(bool done);

private:
	void parseText(string text);
	string * wasCreated;
	string * subject;
	string * text;
	bool done;

	//friend void operator<<(ostream & os, const Task& task);

};

