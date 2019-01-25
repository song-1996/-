#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SDataType;
typedef struct DSListNode
{
	SDataType _data;
	struct DSListNode* _pNext;
	struct DSListNode* _pPre;
}Node;

void DSListInit(Node** _pHead);
void DSListDestroy(Node** _pHead);
void DSListPushBack(Node* _pHead, SDataType data);
void DSListPopBack(Node* _pHead);
void DSListPushFront(Node* _pHead, SDataType data);
void DSListPopFront(Node* _pHead);
void DSListInsert(Node* pos,SDataType data);
void DSListErase(Node* _pHead, Node* pos);
Node* DSListFind(Node* _pHead,SDataType data);
void DSListRemove(Node* _pHead, SDataType data);
void DSListRemoveAll(Node* _pHead, SDataType data);
void DSListPrint(Node* _pHead);