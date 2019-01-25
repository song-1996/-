#include"SList.h"
void printSList(SList* pl)
{
	assert(pl);
	Node* start = pl->_pHead;
	while (pl->_pHead)
	{
		printf("%d-->", pl->_pHead->_data);
		pl->_pHead = pl->_pHead->_pNext;
	}
	pl->_pHead = start;
	printf("NULL\n");
}
void SListInit(SList* pl)
{
	assert(pl);
	pl->_pHead = NULL;
}
void SListDestroy(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
		return;
	else
	{
		Node* p = pl ->_pHead;
		while (p)
		{
			Node* _Del = p;
			p = p->_pNext;
			free(_Del);
		}
	}
}
Node* BuyNewNode(SDataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_pNext = NULL;
	return NewNode;
}
void SListPushBack(SList* pl, SDataType data)
{
	Node* new = BuyNewNode(data);
	assert(pl);
	if (pl->_pHead == NULL)
	{
		pl->_pHead = new;
	}
	else
	{
		Node* prep = pl->_pHead;
		while (pl->_pHead->_pNext)
		{
			pl->_pHead = pl->_pHead->_pNext;
		}
		pl->_pHead->_pNext = new;
		pl->_pHead = prep;
	}
}
void SListPopBack(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
		return;
	else if (pl->_pHead->_pNext == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
		return;
	}
	else
	{
		Node* prep = NULL;
		Node* start = pl->_pHead;
		while (pl->_pHead->_pNext)
		{
			prep = pl->_pHead;
			pl->_pHead = pl->_pHead->_pNext;
		}
		free(pl->_pHead);
		prep->_pNext = NULL;
		pl->_pHead = start;
	}
}
void SListPushFront(SList* pl, SDataType data)
{
	Node* new = BuyNewNode(data);
	assert(pl);
	if (pl->_pHead == NULL)
	{
		pl->_pHead = new;
	}
	else
	{
		new->_pNext = pl->_pHead;
		pl->_pHead = new;
	}
}
void SListPopFront(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
		return;
	else
	{
		Node* del = pl->_pHead;
		pl->_pHead = pl->_pHead->_pNext;
		free(del);
	}
}
void SListInsertAfter(Node* pos, SDataType data)
{
	Node* new = NULL;
	if (pos == NULL)
		return;
	else
	{
		new = BuyNewNode(data);
		new->_pNext = pos->_pNext;
		pos->_pNext = new;
	}
}
void SListErase(SList* pl, Node* pos)
{
	if (pos == NULL)
		return;
	else if (pos == pl->_pHead)
	{
		pl->_pHead = pos->_pNext;
		free(pos);
		pos = NULL;
	}
	else
	{
		Node* p = pl->_pHead;
		Node* prep = NULL;
		while (p->_pNext != pos)
		{
			p = p->_pNext;
		}
		prep = p->_pNext;
		p->_pNext = p->_pNext->_pNext;
		free(prep);
	}
}
Node* SListFind(SList* pl, SDataType data)
{
	assert(pl);
	Node* p = NULL;
	for (p = pl->_pHead; p != NULL; p=p->_pNext)
	{
		if (data == p->_data)
		{
			return p;
		}
	}
	return NULL;
}
int SListSize(SList* pl)
{
	assert(pl);
	Node* p = pl->_pHead;
	int count = 0;
	while (p)
	{
		count++;
		p = p->_pNext;
	}
	return count;
}
int SListEmpty(SList* pl)
{
	assert(pl);
	return (pl->_pHead == NULL);
}
Node* SListFront(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
		return NULL;
	return pl->_pHead;
}
Node* SListBack(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
		return NULL;
	else
	{
		Node* p = pl->_pHead;
		while (p->_pNext)
		{
			p = p->_pNext;
		}
		return p;
	}
}
void SListRemove(SList* pl, SDataType data)
{
	assert(pl);
	SListErase(pl, SListFind(pl, data));
}
void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl);
	Node* pos = NULL;
	//while (pos = SListFind(pl, data))
	//{
	//	SListErase(pl, SListFind(pl, data));
	//}
	Node* p = pl->_pHead;
	while (p)
	{
		if (data == p->_data)
		{
			Node* pcur = p;
			p = p->_pNext;
			SListErase(pl, pcur);
		}
		else
		p = p->_pNext;
	}
}
///////////////////////////////////////////
//void test(void)
//{
//	SList s;
//	SListInit(&s);
//	SListPushBack(&s, 1);
//	SListPushBack(&s, 2);
//	SListPushBack(&s, 3);
//	SListPushBack(&s, 4);
//	printSList(&s);
//	SListPopBack(&s);
//	SListPopBack(&s);
//	SListPopBack(&s);
//	printSList(&s);
//	SListDestroy(&s);
//}
//void test1()
//{
//	SList s;
//	SListInit(&s);
//	SListPushFront(&s,0);
//	SListPushFront(&s, 1);
//	SListPushFront(&s, 2);
//	SListInsertAfter(SListFind(&s, 2), 5);
//	SListPushFront(&s, 3);
//	printSList(&s);
//	//SListPopFront(&s);
//	//SListPopFront(&s);
//	SListErase(&s, SListFind(&s, 2));
//	printSList(&s);
//	SListDestroy(&s);
//}
void test2()
{
	SList s;
	SListInit(&s);
	SListPushFront(&s, 0);
	SListPushFront(&s, 1);
	SListPushFront(&s, 1);
	SListPushFront(&s, 1);
	SListPushFront(&s, 1);

	SListPushFront(&s, 2);
	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	/*SListRemove(&s, 2);*/
	SListRemoveAll(&s, 1);
	printSList(&s);
	//Node* a=SListFront(&s);
	//Node* a = SListBack(&s);
	//printf("%d\n", a->_data);
	//printf("%d\n",SListSize(&s));
	//int a=SListEmpty(&s);
	//printf("%d\n", a);
	SListDestroy(&s);
}