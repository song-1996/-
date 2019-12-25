#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

#if 0
typedef int HDatatype;
typedef int(*pf)(HDatatype a, HDatatype b);
typedef struct Heap
{
	HDatatype* array;
	int size;
	int capacity;
	pf cmp;
}Heap;

void CreatHeap(Heap* hp, int arr[], int size,pf Less);
void InsertHeap(Heap* hp, HDatatype data);
void EraseHeap(Heap* hp);
int SizeHeap(Heap* hp);
int EmptyHeap(Heap* hp);
void SortHeap(Heap* hp);
void DestroyHeap(Heap* hp);
void Print(Heap* hp);
int Greater(HDatatype e1, HDatatype e2);
int Less(HDatatype e1, HDatatype e2);
#endif

typedef int HDataType;
typedef int(*pf)(HDataType e1, HDataType e2);
typedef struct Heap
{
	HDataType* array;
	int size;
	int capacity;
	pf cmp;
}Heap;

void CreatHeap(Heap* h,int* arr,int size,pf cmp);
void InsertHeap(Heap* h, HDataType data);
void EraseHeap(Heap* h);
int size(Heap* h);
int empty(Heap* h);
void Print(Heap* h);
void DestroyHeap(Heap* h);
int Less(HDataType e1, HDataType e2);
int Greater(HDataType e1, HDataType e2);
