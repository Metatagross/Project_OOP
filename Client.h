#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>
#include "Saloon.h"
using namespace std;
class Client
{
private:
	string name;
	string hallName;
	int row;
	int column;
public:
	Client(string name,string hallName, int row, int column)
	{
		this->row = row;
		this->column = column;
		this->name = name;
		this->hallName = hallName;
	}
	friend ostream& operator<<(ostream& os, Client& client)
	{
		os << "Name: " << client.name << "\n" << "Hall Name: " << client.hallName << "\n" << "Row: " << client.row << "\n" << "Column: " << client.column << endl;
		return os;
	}
};

#endif // !CLIENT_H
