#pragma once
#include "Header.h"
using namespace std;
class Task
{
public:
	//info:
	//	Constructor that takes text with data
	Task(string textToParse);
	~Task();
	//info:
	//	Parse text with date of creation, subject and text to field values
	void parseText(string text);
	void changeDoneState();
	string to_string();
	string getWasCreated();
	string getSubject();
	void setSubject(string subject);
	string getText();
	void setText(string text);

private:
	string * wasCreated;
	string * subject;
	string * text;
	bool isDone;

//friend void operator<<(ostream & os, const Task& task);

};

