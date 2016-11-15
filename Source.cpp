#include "Header.h"
#include "DataParser.h"
using namespace std;


int main() {
	/*vector<Task> * tasks = new vector<Task>();
	tasks->push_back(Task("sub", "txt"));
	cout << tasks->at(0).to_string() << endl;
	*/
	Task tsk = Task("sub0", "txt0");
	User me = User("~email~login~password~" + tsk.to_string() + "~");
	cout << me.to_string() << endl;
	me.addTask("sub1", "txt1");
	cout << me.to_string() << endl;
	me.addTask("sub2", "txt2");
	cout << me.to_string() << endl;
	//DataParser dp("E:\\Education\\Programming\\C++\\ToDoList\\res\\new.txt");
	system("pause");
	return 0;
}

