#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<memory.h>
typedef BTNode* SDataType;
typedef struct Stack
{
	SDataType* arr;
	int size;
	int capacity;
}Stack;

void InitStack(Stack* ps);
void CheckCapacity(Stack* ps);
void PushStack(Stack* ps, SDataType data);
void PopStack(Stack* ps);
int SizeStack(Stack* ps);
int EmptyStack(Stack* ps);
int CapacityStack(Stack* ps);
SDataType GetTopStack(Stack* ps);
void DestroyStack(Stack* ps);