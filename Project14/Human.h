#pragma once
class Human
{
	char* surname;
	char* id;
	int visits;
	int countOfBooks;
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
	void SetSurname(const char* surname);
	void SetId(const char * id);
	void SetVisits(int visits);
	~Human();
};