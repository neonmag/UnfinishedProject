#include <iostream>
#include "Library.h"
#include "Methods.h"

using namespace std;

int main()
{
	char** str = nullptr;
	MakeArray(&str);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);										
	CursorOff(h);																	
	SetConsoleTextAttribute(h, 15);													
	int countOfBooks;																
	cout << "Enter count of books: ";												
	cin >> countOfBooks;															
	cin.ignore();																	
	Book* books = new Book[countOfBooks];											
	InputBooks(&books, countOfBooks);												
	system("cls");																	
	int countOfHumans;																
	cout << "Enter count of humans: ";												
	cin >> countOfHumans;															
	cin.ignore();																	
	Human* humans = new Human[countOfHumans];										
	InputHumans(&humans, countOfHumans);											
	system("cls");																	
	Library library("Bilbo's library");
	Initializate(str, "Find books by name", "Find books by genre", "Find books by author",
		"Most value visitor", "Visitors list","Books on hands","Give book",
		"Return book");
	ShowLibrary(h, library);
	ShowMenu(h, str);
	MoveMenu(h, str, &books, countOfBooks,library,&humans,countOfHumans);
	system("pause");
	delete[]books;
	books = nullptr;
	delete[]humans;
	humans = nullptr;
	Deleting(&str);
}