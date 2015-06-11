#ifndef VECTOR_H
#define	VECTOR_H
#include<iostream>
#include<algorithm>
#include<stdexcept>
template<typename T>
class Vector
{
private:
	int capacity;
	int size;
	T *a;
public:
	Vector();
	Vector<T>(int capacity);
	Vector<T>(const Vector& newVector);
	~Vector();

	void copyArray(T *a, T *b,int size);
	void push_back(const T& value);
	void pop_back();
	void resize(int newCapacity);
	T& back();
	T& front();
	void insert(int index, T value);
	void erase(int index);
	T& operator[](int index);
	Vector& operator=(const Vector& v);
	int getSize();
	int getCapacity();
	bool empty();
	void clear();
	void display();
	void swap(int index1, int index2);
	int find(int first, int last, T& value);
};

template<class T>
Vector<T>::Vector()
{
	capacity = 4;
	size = -1;
	a = new T[capacity];
}
template<class T>
Vector<T>::Vector<T>(int capacity)
{
	this->capacity = capacity;
	size = -1;
	a = new T[capacity];
}
template<class T>
Vector<T>::Vector<T>(const Vector& newVector)
{
	size = newVector.size;
	capacity = newVector.capacity;
	copyArray(a, newVector.a, size);
}
template<class T>
Vector<T>::~Vector()
{
	delete[] a;
}
template<class T>
void Vector<T>::copyArray(T *a, T *b, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = b[i];
	}
}
template<class T>
void Vector<T>::push_back(const T& value)
{
	size++;
	if (size + 1 == capacity)
	{
		resize(2 * capacity);
	}
	a[size] = value;
}
template<class T>
void Vector<T>::pop_back()
{
	if (empty() == 1)
	{
		throw std::invalid_argument("The stack is empty! You cannot pop anything from it!");
	}
	else
	{
		size--;
		if (size + 1 == capacity / 2)
		{
			resize(capacity / 2);
		}
	}
}
template<class T>
void Vector<T>::resize(int newCapacity)
{
	T *b;
	b = new T[capacity];
	capacity = newCapacity;
	copyArray(b, a, size);
	a = new T[capacity];
	copyArray(a, b, size);
	delete[] b;
}
template<class T>
T& Vector<T>::back()
{
	if (size == -1)
	{
		throw std::out_of_range("Error! The vector is empty!");
	}
	return a[size];
}
template<class T>
T& Vector<T>::front()
{
	if (size == -1)
	{
		throw std::out_of_range("Error! There are no elements in this vector!");
	}
	return a[0];
}
template<class T>
void Vector<T>::insert(int index, T value)
{
	if (size < index && index < capacity)
	{
		a[index] = value;
		size = index;
	}
	if (index>capacity)
	{
		throw std::invalid_argument("Error! Insertion failed!");
	}
	else if (index<=size)
	{
		size++;
		if (size + 1 == capacity)
		{
			resize(2 * capacity);
		}
		for (int i = size + 1; i > index; i--)
		{
			a[i] = a[i - 1];
		}
		a[index] = value;
	}
}
template<class T>
void Vector<T>::erase(int index)
{
	if (index > size)
	{
		throw std::out_of_range("The index is out of vector's range!");
	}
	else
	{
		for (int i = index; i < size; i++)
		{
			a[i] = a[i + 1];
		}
		size--;
		if (size + 1 == capacity / 2)
		{
			resize(capacity / 2);
		}
	}
	
}
template<class T>
Vector<T>& Vector<T>:: operator=(const Vector& v)
{
	Vector<T> newV;
	newV.capacity = v.capacity;
	newV.size = v.size;
	for (int i = 0; i <v.size; i++)
	{
		newV.a[i] = v.a[i];
	}
	return newV;
}
template<class T>
T& Vector<T>:: operator[](int index)
{
	if (index > size||index<0)
	{
		throw std::out_of_range("Error! Cannot return element!");
	}
	return a[index];
}
template<class T>
int Vector<T>::getSize()
{
	return size + 1;
}
template<class T>
int Vector<T>::getCapacity()
{
	return capacity;
}
template<class T>
bool Vector<T>::empty()
{
	return size == -1;
}
template<class T>
void Vector<T>::clear()
{
	for (int i = size; i >= 0; i--)
	{
		size--;
		if (size + 1 == capacity / 2)
		{
			resize(capacity / 2);
		}
	}
}
template<class T>
void Vector<T>::display()
{
	if (getSize() == 0)
	{
		cout << "The vector is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < getSize(); i++)
		{
			cout << operator[](i) << endl;
			cout << endl;
		}
	}
}
template<class T>
void Vector<T>::swap(int index1, int index2)
{
	T c;
	c = a[index1];
	a[index1] = a[index2];
	a[index2] = c;
}
template<class T>
int Vector<T>::find(int first, int last, T& value)
{
	for (int i = 0; i < getSize(); i++)
	{
		if (a[i]==value)
		{
			return i;
		}
	}
	return getSize();
}
#endif