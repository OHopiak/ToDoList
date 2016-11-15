#pragma once
#include "Header.h"
#include "User.h"
#include <fstream>
using namespace std;

class DataParser
{
public:
	DataParser(string name);
	User * getUser(string login, string password);
	void addUser(string email, string login, string password);
	int restoreUser(string email);
	bool isInUsers(string email);
	~DataParser();

private:
	void readData(string name);
	void decodeData();
	void parseData();
	void prepareData();
	void encodeData();
	void putData(string name);
	string filename;
	string data;
	vector<User> users;
};

