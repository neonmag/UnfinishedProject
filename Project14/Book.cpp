#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(const char* author)
{
	if (this->author != nullptr)
	{
		delete[]this->author;
	}
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
}

Book::Book(const char* genre,const char* author) :Book(author)
{
	if (this->genre != nullptr)
	{
		delete[]this->genre;
	}
	this->genre = new char[strlen(genre) + 1];
	strcpy_s(this->genre, strlen(genre) + 1, genre);
}

Book::Book(const char* name,const char* genre,const char* author) :Book(genre,author)
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Book::Book(bool present,const char* name,const char* genre,const char* author) :Book(name,genre,author)
{
	this->present = present;
}

Book::Book(Book& obj)
{
	if (this->genre != nullptr)
	{
		delete[]this->genre;
	}
	if (this->author != nullptr)
	{
		delete[]this->author;
	}
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->author = new char[strlen(obj.author) + 1];
	strcpy_s(this->author, strlen(obj.author) + 1, obj.author);
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	this->genre = new char[strlen(obj.genre) + 1];
	strcpy_s(this->genre, strlen(obj.genre) + 1, obj.genre);
	this->present = obj.present;
}

void Book::Input()
{
	this->author = nullptr;
	this->name = nullptr;
	this->genre = nullptr;
	this->present = false;
	cout << "\nEnter author name: ";
	this->author = new char[20];
	cin.getline(this->author, 19);
	cout << "\nEnter book genre: ";
	this->genre = new char[20];
	cin.getline(this->genre, 19);
	cout << "\nEnter book name: ";
	this->name = new char[20];
	cin.getline(this->name, 19);
	cout << "\nBook present,or not(1,or 0): ";
	cin >> this->present;
	while (this->present != 0 && this->present != 1)
	{
		cout << "\nBook present,or not(1,or 0): ";
		cin >> this->present;
	}
	cout << endl;
	cin.ignore();
}

void Book::Output() const
{
	cout << "\nAuthor name: " << this->author;
	cout << "\nBook name: " << this->name;
	cout << "\nGenre: " << this->genre;
	if (present == true)
	{
		cout << "\nBook present\n";
	}
	else
	{
		cout << "\nBook not present\n";
	}
}

const char* Book::GetName()
{
	return this->name;
}

const char* Book::GetAuthor()
{
	return this->author;
}

const char* Book::GetGenre()
{
	return this->genre;
}

bool Book::GetPresent()
{
	return this->present;
}

void Book::SetName(const char * name)
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Book::SetGenre(const char* genre)
{
	if (this->genre != nullptr)
	{
		delete[]this->genre;
	}
	this->genre = new char[strlen(genre) + 1];
	strcpy_s(this->genre, strlen(genre) + 1, genre);
}

void Book::SetAuthor(const char* author)
{
	if (this->author != nullptr)
	{
		delete[]this->author;
	}
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
}

void Book::SetPresent(bool present)
{
	this->present = present;
}

Book::~Book()
{
	delete[]this->author;
	this->author = nullptr;
	delete[]this->name;
	this->name = nullptr;
	delete[]this->genre;
	this->genre = nullptr;
}