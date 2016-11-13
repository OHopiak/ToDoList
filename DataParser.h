#pragma once
#include "Header.h"
#include "User.h"
#include <fstream>
using namespace std;

class DataParser
{
public:
	DataParser(string name);
	User getUser(string login, string password);
	~DataParser();

private:
	void readData(string name);
	void decodeData();
	void encodeData();
	string * data;
	vector<User> * users;
};

