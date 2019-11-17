#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

typedef int SDataType;
typedef struct Stack
{
	SDataType* arr;
	int size;
	int capacity;
}Stack;


void InitStack(Stack* s);
void DestroyStack(Stack* s);
void PushStack(Stack* s, SDataType data);
void PopStack(Stack* s);
int SizeStack(Stack* s);
int Capacity(Stack* s);
SDataType GetTopStack(Stack* s);
int EmptyStack(Stack* s);