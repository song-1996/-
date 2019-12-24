#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;
typedef struct Queue
{
	QDataType arr[5];
	int front;
	int rear;
}Queue;

void InitQueue(Queue* q);
void DestroyQueue(Queue* q);
void PushQueue(Queue* q, QDataType data);
void PopQueue(Queue* q);
QDataType front(Queue* q);
QDataType rear(Queue* q);
int empty(Queue* q);
int length(Queue* q);
void Print(Queue* q);