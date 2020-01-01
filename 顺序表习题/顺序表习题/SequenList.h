#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

typedef int SDataType;
typedef struct SequenList
{
	int* arr;
	int size;
	int capacity;
}SequenList;

void InitSequenList(SequenList* sq);
void DestroySequenList(SequenList* sq);
void PushSequenList(SequenList* sq, SDataType data);
void PushSequenListX(SequenList* sq, SDataType data, int pos);
void PopSequenList(SequenList* sq);
SDataType GetMax(SequenList* sq);
int GetMaxPos(SequenList* sq);