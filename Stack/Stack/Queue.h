#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;
typedef struct Node
{
	struct Node* _next;
	QDataType _data;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;

void InitQueue(Queue* q);
void DestroyQueue(Queue* q);
void Push(Queue* q, QDataType data);
void Pop(Queue* q);
int Size(Queue* q);
int Empty(Queue* q);
QDataType Front(Queue* q);
QDataType Rear(Queue* q);
