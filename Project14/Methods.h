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
	*str = new char* [5];
	for (int i = 0; i < 5; i++)
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
	const char* visitList)
{
	strcpy_s(str[0], strlen(findBook) + 1, findBook);
	strcpy_s(str[1], strlen(findGenre) + 1, findGenre);
	strcpy_s(str[2], strlen(findAuthor) + 1, findAuthor);
	strcpy_s(str[3], strlen(mvVisitor) + 1, mvVisitor);
	strcpy_s(str[4], strlen(visitList) + 1, visitList);
}

void ShowMenu(HANDLE h, char** str)
{
	COORD position{ 20,5 };
	for (int i = 0; i < 5; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << str[i];
		position.Y += 2;
	}
}

void ShowBooks(Book** obj, int amount, HANDLE h)
{
	system("cls");
	COORD position { 0,2 };
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < amount; i++)
	{
		SetConsoleCursorPosition(h, position);
		cout << "Book " << i + 1 << ": " << (*obj)[i].GetName();
		position.Y += 2;
	}
	int key = _getch();
}

void MoveMenu(HANDLE h, char** str, Book** obj, int amount)
{
	COORD position{ 20,5 };
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	SetConsoleCursorPosition(h, position);
	int counter = 0;
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
			}
			else if (position.Y <= 13)
			{
				return;
			}
			break;
		case Keys::DOWN:
			if (position.Y == 13)
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

void ShowLibrary(HANDLE h, Library& obj)
{
	COORD position{ 0,0 };
	SetConsoleCursorPosition(h, position);
	obj.Output();
}

void InputBooks(Book** obj, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		(*obj)[i].Input();
	}
}

void Deleting(char** str)
{
	for (int i = 0; i < 5; i++)
	{
		delete[] str[i];
	}
	delete[] str;
}