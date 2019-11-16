#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[5];
	char addr[25];
	char tele[15];
} PeoInfo;

//typedef struct contact
//{
//	PeoInfo pep[1000];
//	int sz;
//}contact;

typedef struct contact
{
	PeoInfo* pep;
	int sz;
	int count;
}contact;

void Init_Info(contact* pc);
void ADD_Info(contact* pc);
void SHOW_Info(contact* pc);
int SEARCH_Info(contact* pc);
void DEL_Info(contact* pc);
void MODIFY_Info(contact* pc);
void EMPTY_Info(contact* pc);
void SORT_Info(contact* pc);
void EXIT_Info(contact* pc);
void read_Info(contact* pc);
void save_Info(contact* pc);