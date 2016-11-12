#include "Header.h"
#include "User.h"
using namespace std;


int main(){
	Task my("Title|some text|now|");
	//my.setText("Hi");
	cout << my.to_string() << endl;
	system("pause");
	return 0;
}

