#pragma once
#include "Header.h"
using namespace std;
class Task
{
	static enum Priority { HIGH, MEDIUM, LOW };

public:
	Task(string dateNtime, string wasCreated, string subject, string text, Priority priority);
	~Task();
	friend void operator<<(ostream & os, const Task& task);
	string to_string();
private:
	string dateNtime;
	string wasCreated;
	string subject;
	string text;
	Priority priority;

};

