#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QDataType;
typedef struct QListNode
{
	QDataType data;
	struct QListNode* pNext;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;

void QueueInit(Queue* pc);
void QueuePush(Queue* pc,QDataType data);
void QueuePop(Queue* pc);
QDataType QueueFront(Queue* pc);
QDataType QueueRear(Queue* pc);
int QueueSize(Queue* pc);
int QueueEmpty(Queue* pc);
void QueueDestroy(Queue* pc);
