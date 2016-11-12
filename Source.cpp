#include "Header.h"
#include "User.h"
using namespace std;


int main(){
	Task * my = new Task("****Title****Hohoho****true****now****");
	my->setText("Hi");
	cout << my->to_string();

	system("pause");
	return 0;
}

