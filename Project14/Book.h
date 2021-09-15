#pragma once
class Book
{
	char* author;
	char* genre;
	char* name;
	bool present;
public:
	Book() = default;
	Book(const char* author);
	Book(const char* genre, const char* author);
	Book(const char* name, const char* genre, const char* author);
	Book(bool present, const char* name, const char* genre, const char* author);
	Book(Book& obj);
	void Input();
	void Output() const;
	const char* GetName();
	const char* GetAuthor();
	const char* GetGenre();
	bool GetPresent();
	void SetName(const char* name);
	void SetGenre(const char* genre);
	void SetAuthor(const char* author);
	void SetPresent(bool present);
	~Book();
};