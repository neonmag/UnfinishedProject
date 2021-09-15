#include "Human.h"
#include <iostream>

using namespace std;

Human::Human(int countOfBooks)
{
	this->countOfBooks = countOfBooks;
}

Human::Human(int visits, int countOfBooks) :Human(countOfBooks)
{
	this->visits = visits;
}

Human::Human(const char* surname,int visits,int countOfBooks):Human(visits,countOfBooks)
{
	if (this->surname != nullptr)
	{
		delete[]this->surname;
	}
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}

Human::Human(const char* id, const char* surname,int visits,int countOfBooks) :Human(surname,visits,countOfBooks)
{
	if (this->id != nullptr)
	{
		delete[]this->id;
	}
	this->id = new char[strlen(id) + 1];
	strcpy_s(this->id, strlen(id) + 1, id);
}

Human::Human(Human& obj)
{
	if (this->surname != nullptr)
	{
		delete[]this->surname;
	}
	if (this->id != nullptr)
	{
		delete[]this->id;
	}
	this->id = new char[strlen(obj.id) + 1];
	strcpy_s(this->id, strlen(obj.id) + 1, obj.id);
	this->surname = new char[strlen(obj.surname) + 1];
	strcpy_s(this->surname, strlen(obj.surname) + 1, obj.surname);
}

void Human::Input()
{
	this->surname = new char[20];
	cout << "\nEnter your surname: ";
	cin.getline(this->surname, 19);
	cout << "\nEnter your id: ";
	this->id = new char[20];
	cin.getline(this->id, 19);
	cout << "\nEnter count of visits: ";
	cin >> this->visits;
	cin.ignore();
}

void Human::Output() const
{
	cout << "\nSurname: " << this->surname;
	cout << "\nID: " << this->id;
}

const char* Human::GetSurname()
{
	return this->surname;
}

const char* Human::GetId()
{
	return this->id;
}

int Human::GetVisits()
{
	return this->visits;
}

void Human::SetSurname(const char* surname)
{
	if (this->surname != nullptr)
	{
		delete[]this->surname;
	}
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Human::SetId(const char* id)
{
	if (this->id != nullptr)
	{
		delete[]this->id;
	}
	this->id = new char[strlen(id) + 1];
	strcpy_s(this->id, strlen(id) + 1, id);
}

void Human::SetVisits(int visits)
{
	this->visits = visits;
}

Human::~Human()
{
	delete[]this->surname;
	this->surname = nullptr;
	delete[]this->id;
	this->id = nullptr;
}
