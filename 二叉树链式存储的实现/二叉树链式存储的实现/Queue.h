#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<memory.h>
typedef BTNode* QDataType;
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;

void InitQueue(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueRear(Queue* q);
void DestroyQueue(Queue* q);