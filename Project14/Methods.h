#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include "Enums.h"
#include "Library.h"

using namespace std;

void MakeArray(char*** str)
{
	*str = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		(*str)[i] = new char[25];
	}
}

void CursorOff(HANDLE h)
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 100;
	cursor.bVisible = false;
	SetConsoleCursorInfo(h, &cursor);
}

void Initializate(char** str, const char* findBook, const char* findGenre, const char* findAuthor, const char* mvVisitor,
	const char* visitList, const char* countOfBooksOnHand, const char* giveBook, const char* returnBook)
{
	strcpy_s(str[0], strlen(findBook) + 1, findBook);
	strcpy_s(str[1], strlen(findGenre) + 1, findGenre);
	strcpy_s(str[2], strlen(findAuthor) + 1, findAuthor);
	strcpy_s(str[3], strlen(mvVisitor) + 1, mvVisitor);
	strcpy_s(str[4], strlen(visitList) + 1, visitList);
	strcpy_s(str[5], strlen(countOfBooksOnHand) + 1, countOfBooksOnHand);
	strcpy_s(str[6], strlen(giveBook) + 1, giveBook);
	strcpy_s(str[7], strlen(returnBook) + 1, returnBook);
}

void ShowMenu(HANDLE h, char** str)
{
	COORD position{ 20,5 };
	for (int i = 0; i < 8; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << str[i];
		position.Y += 2;
	}
}

void ShowBooks(Book** obj, int amount, HANDLE h)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < amount; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << "Book " << i + 1 << ": " << (*obj)[i].GetName();
		position.Y += 2;
	}
	int key = _getch();
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void ShowGenre(Book** obj, int amount, HANDLE h)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < amount; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << "Genre " << i + 1 << ": " << (*obj)[i].GetGenre();
		position.Y += 2;
	}
	int key = _getch();
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void ShowAuthor(Book** obj, int amount, HANDLE h)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < amount; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << "Author " << i + 1 << ": " << (*obj)[i].GetAuthor();
		position.Y += 2;
	}
	int key = _getch();
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void ShowGiveBook(Book** obj, int amount, HANDLE h)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < amount; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << "Book " << i + 1 << ": " << (*obj)[i].GetName();
		position.Y += 2;
	}
	position = { 0,0 };
	SetConsoleCursorPosition(h, position);
	cout << "Choose your book: ";
	int index;
	cin >> index;
	cin.ignore();
	int key = _getch();
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void ShowLibrary(HANDLE h, Library& obj)
{
	COORD position{ 0,0 };
	SetConsoleCursorPosition(h, position);
	obj.Output();
}

void ShowBooksOnHand(HANDLE h, Human** obj, int amount)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	SetConsoleCursorPosition(h, position);
	for (int i = 0; i < amount; i++)
	{
		cout << "Visitor " << (*obj)[i].GetSurname() << " with " << (*obj)[i].GetCountOfBooks() << " books";
		position.Y += 2;
		SetConsoleCursorPosition(h, position);
	}

	int key = _getch();
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void ReturnBook(Book** obj, int amount, HANDLE h,int numOfVisitor,Human **hum)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	SetConsoleCursorPosition(h, position);
	int temp;
	cout << "Would you return book(1 - yes,or 2 - no): ";
	cin >> temp;
	while (temp < 1 && temp > 2)
	{
		system("cls");
		SetConsoleCursorPosition(h, position);
		cout << "Would you return book(yes,or no): ";
		cin >> temp;
	}
	if (temp == 1)
	{
		(*obj)[numOfVisitor].SetPresent(true);
		(*hum)[numOfVisitor].SetCountOfBooks(0);
		return;
	}
	else
	{
		return;
	}
}

void ShowVisits(Human** obj, int amount, HANDLE h, int &numOfVisitor)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < amount; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << "Visitor " << i + 1 << ": " << (*obj)[i].GetSurname() << " " << (*obj)[i].GetVisits() << " visits with " << (*obj)[i].GetId() << " id";
		position.Y += 2;
	}
	int key = _getch();
	position = { 0,0 };
	SetConsoleCursorPosition(h, position);
	cout << "Enter your index: ";
	cin >> numOfVisitor;
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void ShowMvp(Human** obj, int amount, HANDLE h)
{
	system("cls");
	COORD position{ 0,2 };
	SetConsoleTextAttribute(h, 15);
	int temp = 0;
	int tempVisits = (*obj)[0].GetVisits();
	for (int i = 0; i < amount; i++)
	{
		if ((*obj)[i].GetVisits() > tempVisits)
		{
			temp = i;
		}
	}
	for (int i = 0; i < amount; i++)
	{
		if (i == temp)
		{
			cout << "MVP visitor: " << (*obj)[i].GetSurname();
		}
	}
	int key = _getch();
	while (key != Keys::ENTER)
	{
		key = _getch();
	}
	return;
}

void MoveMenu(HANDLE h, char** str, Book** obj, int amount, Library& lib, Human** hum, int amountOfHumans)
{
	COORD position{ 20,5 };
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	SetConsoleCursorPosition(h, position);
	int counter = 0;
	int numOfVisitor = 0;
	cout << str[counter];
	int key = _getch();
	while (true)
	{
		key = _getch();
		switch (key)
		{
		case Keys::ENTER:
			if (position.Y == 5)
			{
				ShowBooks(obj, amount, h);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 7)
			{
				ShowGenre(obj, amount, h);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 9)
			{
				ShowAuthor(obj, amount, h);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 11)
			{
				ShowMvp(hum, amountOfHumans, h);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 13)
			{
				ShowVisits(hum, amountOfHumans, h, numOfVisitor);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 15)
			{
				ShowBooksOnHand(h, hum, amountOfHumans);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 17)
			{
				ShowGiveBook(obj, amount, h);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			if (position.Y == 19)
			{
				ReturnBook(obj, amount, h,numOfVisitor,hum);
				system("cls");
				ShowLibrary(h, lib);
				ShowMenu(h, str);
			}
			break;
		case Keys::DOWN:
			if (position.Y == 19)
			{
				break;
			}
			else
			{
				SetConsoleTextAttribute(h, 15);
				SetConsoleCursorPosition(h, position);
				cout << str[counter];
				position.Y += 2;
				counter++;
				SetConsoleTextAttribute(h, FOREGROUND_BLUE);
				SetConsoleCursorPosition(h, position);
				cout << str[counter];
			}
			break;
		case Keys::UP:
			if (position.Y == 5)
			{
				break;
			}
			else
			{
				SetConsoleTextAttribute(h, 15);
				SetConsoleCursorPosition(h, position);
				cout << str[counter];
				position.Y -= 2;
				counter--;
				SetConsoleTextAttribute(h, FOREGROUND_BLUE);
				SetConsoleCursorPosition(h, position);
				cout << str[counter];
			}
			break;
		default:
			break;
		}
	}
}

void InputBooks(Book** obj, int amount)
{
	(*obj)[0].Input();
	for (int i = 1; i < amount; i++)
	{
		(*obj)[i].Input();
		for (int j = 0; j < i; j++)
		{
			if ((*obj)[i].GetName() != (*obj)[j].GetName())
			{
				(*obj)[i].SetName();
			}
		}
	}
}

void InputHumans(Human** obj, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		(*obj)[i].Input();
	}
}

void Deleting(char*** str)
{
	for (int i = 0; i < 8; i++)
	{
		delete[](*str)[i];
	}
	delete[] * str;
	*str = nullptr;
}