#pragma once
#include "Human.h"
#include "Book.h"
class Library
{
	char* nameLibrary;
public:
	Library() = default;
	Library(const char* nameLibrary);
	Library(Library& obj);
	void Input();
	void Output();
	void Setlibrary(const char* nameLibrary);
	const char* GetLibrary();
	~Library();
};