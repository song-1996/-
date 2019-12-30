#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SDataType;
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node;

void SListPushBack(Node* pl, SDataType data);
Node* deleteDuplication(Node* pHead);