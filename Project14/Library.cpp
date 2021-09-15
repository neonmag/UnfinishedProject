#include "Library.h"
#include <iostream>

using namespace std;

Library::Library(const char* nameLibrary)
{
	if (this->nameLibrary != nullptr)
	{
		delete[]this->nameLibrary;
	}
	this->nameLibrary = new char[strlen(nameLibrary) + 1];
	strcpy_s(this->nameLibrary, strlen(nameLibrary) + 1, nameLibrary);
}

Library::Library(Library& obj)
{
	if (this->nameLibrary != nullptr)
	{
		delete[]this->nameLibrary;
	}
	this->nameLibrary = new char[strlen(obj.nameLibrary) + 1];
	strcpy_s(this->nameLibrary, strlen(obj.nameLibrary) + 1, obj.nameLibrary);
}

void Library::Input()
{
	cout << "\nEnter name of library: ";
	this->nameLibrary = new char[20];
	cin.getline(this->nameLibrary, 19);
}

void Library::Output()
{
	cout << this->nameLibrary;
	cout << endl;
}

void Library::Setlibrary(const char* nameLibrary)
{
	if (this->nameLibrary != nullptr)
	{
		delete[]this->nameLibrary;
	}
	this->nameLibrary = new char[strlen(nameLibrary) + 1];
	strcpy_s(this->nameLibrary, strlen(nameLibrary) + 1, nameLibrary);
}

const char* Library::GetLibrary()
{
	return this->nameLibrary;
}

Library::~Library()
{
	delete[]this->nameLibrary;
	this->nameLibrary = nullptr;
}
