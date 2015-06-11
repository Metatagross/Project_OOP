#include "Vector.h"
#include "Saloon.h"
#include "Client.h"
#include<string>
#include<iostream>
using namespace std;
int checkName(string hallName, Vector<Saloon*>* complex)
{
	for (int i = 0; i < complex->getSize(); i++)
	{
		if (hallName == (*complex)[i]->getName())
		{
			return i;
		}
	}
	return complex->getSize() + 1;
}
bool checkForSigns(string name)
{
	string symbols = "!@#$%^&*/+-";
	string numbers = "0123456789";
	bool counterSym = true;
	bool counterNum = true;
	for (unsigned int i = 0; i < symbols.size(); i++)
	{
		if (name.find(symbols[i]) != string::npos)
		{
			counterSym = false;
		}
	}
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		if (name.find(numbers[i]) != string::npos)
		{
			counterNum = false;
		}
	}

	if (counterNum == true && counterSym == true)
	{
		return true;
	}
	else
	{
		return false;
	}

}
int main()
{
	Vector<Saloon*>* complex = new Vector<Saloon*>();
	Vector<Client*>* archive = new Vector<Client*>();
	Saloon* saloon;
	Client* client;
	int width, height, row, column;
	string name;
	string hallName;
	string command;
	for (int i = 0; i < 10; i++)
	{
		cin >> name;
		cin >> width >> height;
		
		saloon = new Saloon(width, height,name);
		complex->push_back(saloon);
	}
	//for (int i = 0; i < 10; i++)
	//{
	//	(*complex)[i]->display();
	//}
	while (true)
	{
		cout << "Welcome to the Great complex!" << endl;
		cout << "Write command: ";
		cin >> command;
		while (command != "register" && command != "exit"&&command != "archive"&&command != "clear")
		{
			cout << "Wrong command! Try again:";
			cin >> command;
		}
		if (command == "register")
		{
			cout << "Write your name to make reservation: ";
			cin >> name;
			while (checkForSigns(name) != true)
			{
				cout << "Your name contains unexeptable symbol or number!";
				cout << "Try again: ";
				cin >> name;
			}
			cout << "Now write the name of the hall: ";
			cin >> hallName;
			if (checkName(hallName, complex) == (complex->getSize() + 1))
			{
				cout << "There is no such a hall in the complex!" << endl;
			}
			else
			{
				(*complex)[checkName(hallName, complex)]->display();
			}

			cout << "Choose your place: "<<endl;
			cin >> row >> column;
			(*complex)[checkName(hallName, complex)]->fillPlace(row, column);
			system("cls");
			cout << "You are registered!" << endl;
			client = new Client(name, (*complex)[checkName(hallName, complex)]->getName(), row, column);
			archive->push_back(client);
			(*complex)[checkName(hallName, complex)]->display();
		}
		else if (command == "archive")
		{
			while (true)
			{
				cout << "Welcome! Enter order: ";
				string order;
				int index;
				cin >> order;
				if (order == "get")
				{
					cout << "Enter index: ";
					cin >> index;
					cout << *(*archive)[index] << endl;
				}
				else if (order == "display")
				{
					archive->display();
				}
				else if (order == "erase")
				{
					cout << "Enter index: ";
					cin >> index;
					archive->erase(index);
				}
				else if (order == "empty")
				{
					cout << archive->empty() << endl;
				}
				else if (order == "clear")
				{
					cout << "Cleared" << endl;
					archive->clear();
				}
				else if (order == "exit")
				{
					break;
				}
			}
		}
		else if (command == "clear")
		{
			system("cls");
		}
		else
		{
			break;
		}
	}
	cout << endl;
	return 0;
}
/* Примерен вход:
Congress 12 12
Conference 15 15
Hall666 8 6
Documentaries 12 5
Aula 19 6
Music 20 10
Shannon 15 10
Chomsky 8 8
S-size 5 5
Galerie 18 10
*/