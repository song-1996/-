#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;
#include"Person.h"

void Person::InitPerson(const char* name, int age, const char* gender)
{
	strcpy(_name, name);
	_age = age;
	strcpy(_gender, gender);
}
void Person::Print()
{
	cout << _name << ' ' << _age << ' ' << _gender << endl;
}
int main()
{
	Person s;
	s.InitPerson("zhangsan", 20, "man");
	s.Print();
	system("pause");
	return 0;

}