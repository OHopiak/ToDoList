#include "Task.h"



Task::Task(string dateNtime, string wasCreated, string subject, string text, Priority priority)
	:dateNtime(dateNtime), wasCreated(wasCreated), subject(subject), text(text), priority(priority)
{
}

Task::~Task()
{
}

string Task::to_string()
{
	return "Hi nigga\n";
}

void operator<<(ostream & os, Task & task)
{
	os << task;
}
