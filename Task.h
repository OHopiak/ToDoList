#pragma once
#include "Header.h"
#include <ctime>
using namespace std;
class Task
{
public:
	//info:
	//	Constructor used to parse data of existing Task
	Task(string textToParse);
	//info:
	//	Constructor used to create new Task
	Task(string subject, string text);
	~Task();
	//info:
	//	Parse text with subject, text and date of creation to field values 
	//	format: dd/mm/yyyy
	string dateNow();
	void changeDoneState();
	//info:
	//	format: |subject|text|date|done|
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
	string wasCreated;
	string subject;
	string text;
	bool done;
};

