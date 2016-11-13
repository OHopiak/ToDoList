#include "DataParser.h"

DataParser::DataParser(string name)
{
	data = new string("");
	users = new vector<User>();
	filename = &name;
	readData(*filename);
	//decodeData();
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
	cout << *data;
	*data = "Hello";
}

void DataParser::decodeData()
{
	for (size_t i = 0; i < data->size(); i++)
	{
		int pos = (int)(data->at(i));
		pos += 20;
		pos %= 256;
		data[i] = (char)pos;
	}
}

void DataParser::encodeData()
{
	for (size_t i = 0; i < data->size(); i++)
	{
		int pos = (int)(data->at(i));
		pos -= 20;
		pos %= 256;
		pos = pos < 0 ? pos + 256 : pos;
		data[i] = (char)pos;
	}
}

void DataParser::putData(string name)
{
	ofstream file;
	file.open(name);
	file << *data;
	file.close();
}

DataParser::~DataParser()
{
	encodeData();
	putData(*filename);
	cout << "deleted\n";
	delete data;
	delete filename;
	delete users;
}
