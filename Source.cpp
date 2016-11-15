#include "Header.h"
#include "DataParser.h"
using namespace std;


int main() {
	DataParser dp("E:\\Education\\Programming\\C++\\ToDoList\\res\\new.txt");
	User * me = dp.getUser("login2", "password2");
	cout << (me ? me->to_string() : "Does not exist") << endl;
	system("pause");
	return 0;
}

