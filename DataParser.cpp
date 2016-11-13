#include "DataParser.h"

DataParser::DataParser(string name)
{
	data = new string("");
	users = new vector<User>();
	readData(name);
}

void DataParser::readData(string name)
{
	ifstream file(name);
	char c;
	while (file.get(c))
	{
		*data += c;
	}
	file.close();
}

void DataParser::decodeData()
{
}

void DataParser::encodeData()
{
}

DataParser::~DataParser()
{
	cout << "deleted\n";
	delete data;
	delete users;
}
