#pragma once
class Person
{
public:
	void InitPerson(const char* name, int age, const char* gender);
	void Print();
private:
	char _name[20];
	int _age;
	char _gender[5];
};