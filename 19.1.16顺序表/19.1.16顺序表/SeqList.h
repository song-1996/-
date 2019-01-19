#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct SeqList
{
	DataType* arr;
	DataType size;
	DataType capacity;
}* SeqList,SeqList1;

void SeqListInit(SeqList pc);
void SeqListDestroy(SeqList pc);
void SeqListPushBack(SeqList pc,DataType data);
void SeqListPopBack(SeqList pc);
void SeqListPushFront(SeqList pc,DataType data);
void SeqListPopFront(SeqList pc);
void SeqListInsert(SeqList pc,DataType pos,DataType data);
void SeqListErase(SeqList pc, DataType pos);
int SeqListFind(SeqList pc, DataType data);
void SeqListMove(SeqList pc, DataType data);
void SeqListRemove(SeqList pc, DataType data);
int SeqListSize(SeqList pc);
int SeqListCapacity(SeqList pc);
void SeqListEmpty(SeqList pc);
int SeqListGetFront(SeqList pc);
int SeqListGetBack(SeqList pc);
void PrintSeqList(SeqList pc);