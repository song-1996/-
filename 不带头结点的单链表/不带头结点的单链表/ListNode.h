#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int NDataType;
typedef struct ListNode
{
	struct ListNode* _next;
	NDataType _data;
}ListNode;

void InitListNode(ListNode** pl);
void DestroyListNode(ListNode** pl);
void PushBack(ListNode** pl, NDataType data);
void PopBack(ListNode** pl);
void PushFront(ListNode** pl, NDataType data);
void PopFront(ListNode** pl);
void SListInsertAfter(ListNode* pos, NDataType data);
void SListErase(ListNode** pl, ListNode* pos);
ListNode* SListFind(ListNode** pl, NDataType data);
int SListSize(ListNode** pl);
int SListEmpty(ListNode**  pl);
ListNode* SListFront(ListNode**  pl);
ListNode* SListBack(ListNode**  pl);
void SListRemove(ListNode**  pl, NDataType data);
void SListRemoveAll(ListNode**  pl, NDataType data);
ListNode* EntryNodeOfLoop(ListNode* pHead);
////////////////////////////////////////////////////////////
ListNode* swapPairs(ListNode** head);