#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<iostream>
using namespace std;
typedef int SDataType;
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node;
void test();
void SListPushBack(Node* pl, SDataType data);
Node* deleteDuplication(Node* pHead);