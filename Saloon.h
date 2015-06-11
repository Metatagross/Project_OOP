#ifndef SALOON_H
#define SALOON_H
#include<iostream>
#include<string>
using namespace std;
class Saloon
{
private:
	string name;
	int **arena;
	int width;
	int height;
public:
	Saloon();
	Saloon(int size, string name);
	Saloon(int width, int height,string name);
	~Saloon();
	string getName();
	void fillPlace(int& row, int& column);
	void fill();
	void display();
};

Saloon::Saloon()
{
	name = "Saloon1";
	width = 10;
	height = 10;
	arena = new int*[width];
	for (int i = 0; i < width; i++)
	{
		arena[i] = new int[height];
	}
	fill();
}
Saloon::Saloon(int size, string name)
{
	this->name = name;
	width = size;
	height = size;
	arena = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arena[i] = new int[size];
	}
	fill();
}
Saloon::Saloon(int width, int height, string name)
{
	this->name = name;
	this->width = width;
	this->height = height;
	arena = new int*[width];
	for (int i = 0; i < width; i++)
	{
		arena[i] = new int[height];
	}
	fill();
}
Saloon::~Saloon()
{
	for (int i = 0; i < width; i++)
	{
		delete arena[i];
	}
}
string Saloon::getName()
{
	return name;
}
void Saloon::fillPlace(int& row, int& column)
{
	while (arena[row][column]!=0)
	{
		cout << "The seat is reserved! Try again: " << endl;
		cin >> row >> column;
	}
	arena[row][column] = 1;
}
void Saloon::fill()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			arena[i][j] = 0;
		}
	}
}
void Saloon::display()
{
	cout << name << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << arena[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
#endif // !SALOON_H
