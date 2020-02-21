#include"SList.h"
//void printSList(SList* pl)
//{
//	assert(pl);
//	Node* start = pl->_pHead;
//	while (pl->_pHead)
//	{
//		printf("%d-->", pl->_pHead->_data);
//		pl->_pHead = pl->_pHead->_pNext;
//	}
//	pl->_pHead = start;
//	printf("NULL\n");
//}
//void SListInit(SList* pl)
//{
//	assert(pl);
//	pl->_pHead = NULL;
//}
//void SListDestroy(SList* pl)
//{
//	assert(pl);
//	if (pl->_pHead == NULL)
//		return;
//	else
//	{
//		Node* p = pl->_pHead;
//		while (p)
//		{
//			Node* _Del = p;
//			p = p->_pNext;
//			free(_Del);
//		}
//	}
//}
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
//void SListPushBack(SList* pl, SDataType data)
//{
//	Node* new = BuyNewNode(pl, data);
//	assert(pl);
//	if (pl->_pHead == NULL)
//	{
//		pl->_pHead = new;
//	}
//	else
//	{
//		Node* prep = pl->_pHead;
//		while (pl->_pHead->_pNext)
//		{
//			pl->_pHead = pl->_pHead->_pNext;
//		}
//		pl->_pHead->_pNext = new;
//		pl->_pHead = prep;
//	}
//}
//void SListReversal(SList* pl)
//{
//	assert(pl);
//	Node* p = pl->_pHead;
//	Node* q = NULL;
//	Node *tmp=NULL;
//	while (p)
//	{
//		tmp = p->_pNext;
//		p->_pNext = q;
//		q = p;
//		p = tmp;
//	}
//	pl->_pHead = q;
//}
///////////////////
//void test()
//{
//	SList s;
//	SListInit(&s);
//	SListPushBack(&s, 1);
//	SListPushBack(&s, 2);
//	SListPushBack(&s, 3);
//	SListPushBack(&s, 4);
//	SListPushBack(&s, 5);
//	printSList(&s);
//	SListReversal(&s);
//	printSList(&s);
//	SListDestroy(&s);
//}
void SListPushBack(Node* pl, SDataType data)
{
	Node* newnode = BuyNewNode(data);
	assert(pl);
	if (pl->_pNext== NULL)
	{
		pl->_pNext = newnode;
	}
	else
	{
		Node* p = pl->_pNext;
		while (p->_pNext)
		{
			p = p->_pNext;
		}
		p->_pNext = newnode;
	}
}
Node* deleteDuplication(Node* pHead)
{
	if (pHead->_pNext == NULL)
		return NULL;
	Node* Newhead = BuyNewNode(0);
	Newhead->_pNext = NULL;
	Node* pTail = Newhead;
	Node* Next = pHead->_pNext->_pNext;
	Node* pStart = pHead->_pNext;
	while (Next)
	{

		if ((pStart->_data) != (Next->_data))
		{
			pTail->_pNext = pStart;
			pTail= pTail->_pNext;
			pStart = pStart->_pNext;
			Next = Next->_pNext;
		}
		else
		{
			Next = Next->_pNext;
			if (Next)
			{
				pStart = NULL;
				break;
			}
			if (pStart->_data != Next->_data)
			{
				pStart = Next;
				Next = Next->_pNext;
			}
		}
	}
	pTail->_pNext = pStart;
	return Newhead->_pNext;
}

	void _swapPairs(Node** head)
	{
		if (*head == NULL || (*head)->_pNext == NULL)
			return;
		Node* node = (*head)->_pNext->_pNext;
		if ((*head)->_pNext)
			swap((*head), (*head)->_pNext);
		 _swapPairs(&node);
		(*head)->_pNext->_pNext = node;
	}
	Node* swapPairs(Node* head)
	{
		if (head == NULL || head->_pNext == NULL)
			return head;
		Node* node = head->_pNext->_pNext;
		if (head->_pNext)
			swap(head, head->_pNext);
		_swapPairs(&node);
		head->_pNext->_pNext = node;
		return head;
	}

void test()
{
	Node head;
	head._pNext = NULL;
	SListPushBack(&head,1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);
	swapPairs(head._pNext);
}