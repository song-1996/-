#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int SDatatype;
typedef struct Stack
{
	int top;
	int capacity;
	SDatatype* arr;
}Stack;

//typedef struct
//{
//	Stack s1;
//	Stack s2;
//} MinStack;
typedef struct
{
	Stack s1;
	Stack s2;
} MyQueue;
void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps, SDatatype data);
void StackPop(Stack* ps);
int StackSize(Stack* ps);
SDatatype StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackCapacity(Stack* ps);