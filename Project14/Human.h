#pragma once
class Human
{
	char* surname;
	char* id;
	int visits;
	int countOfBooks = 0;
public:
	Human() = default;
	Human(int countOfBooks);
	Human(int visits,int countOfBooks);
	Human(const char* surname,int visits,int countOfBooks);
	Human(const char* id, const char* surname,int visits,int countOfBooks);
	Human(Human& obj);
	void Input();
	void Output()const;
	const char* GetSurname();
	const char* GetId();
	int GetVisits();
	int GetCountOfBooks();
	void SetSurname(const char* surname);
	void SetId(const char * id);
	void SetVisits(int visits);
	void SetCountOfBooks(int countOFBooks);
	~Human();
};