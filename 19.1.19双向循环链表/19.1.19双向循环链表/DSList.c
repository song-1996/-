#include"DSList.h"
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
	NewNode->_pPre = NULL;
	return NewNode;
}
void DSListPrint(Node* _pHead)
{
	assert(_pHead);
	Node* p = _pHead->_pNext;
	while (p!= _pHead)
	{	
		printf("%d  ", p->_data);
		p = p->_pNext;
	}
	printf("\n");
}
void DSListInit(Node** _pHead)
{
	assert(_pHead);
	*_pHead = BuyNewNode(0);
	(*_pHead)->_pNext = (*_pHead);
	(*_pHead)->_pPre = (*_pHead);
}
void DSListDestroy(Node** _pHead)
{
	assert(_pHead);
	Node* p = (*_pHead)->_pNext;
	while (p != (*_pHead))
	{
		Node* del = p;
		p = p->_pNext;
		free(del);
	}
	free(*_pHead);
	(*_pHead) = NULL;
}
void DSListPushBack(Node* _pHead, SDataType data)
{
	Node* New = BuyNewNode(data);
	assert(_pHead);
	New->_pNext = _pHead;
	New->_pPre = _pHead->_pPre;
	_pHead->_pPre->_pNext = New;
	_pHead->_pPre = New;
}
void DSListPopBack(Node* _pHead)
{
	assert(_pHead);
	if (_pHead->_pNext == _pHead)
		return;
	else
	{
		Node* del = _pHead->_pPre;
		del->_pPre->_pNext = _pHead;
		_pHead->_pPre = del->_pPre;
		free(del);
	}
}
void DSListPushFront(Node* _pHead, SDataType data)
{
	Node* New = NULL;
	assert(_pHead);
	New = BuyNewNode(data);
	New->_pNext = _pHead->_pNext;
	New->_pPre = _pHead;
	_pHead->_pNext->_pPre = New;
	_pHead->_pNext = New;
}
void DSListPopFront(Node* _pHead)
{
	assert(_pHead);
	if (_pHead->_pNext == _pHead)
		return;
	else
	{
		Node* del = _pHead->_pNext;
		_pHead->_pNext = del->_pNext;
		del->_pNext->_pPre = _pHead;
		free(del);
	}
}
Node* DSListFind(Node* _pHead,SDataType data)
{
	assert(_pHead);
	Node* p = _pHead->_pNext;
	while (p != _pHead)
	{
		if (data == p->_data)
			return p;
		p = p->_pNext;
	}
	return NULL;

}
void DSListInsert(Node* pos, SDataType data)
{
	Node* New = NULL;
	if (pos == NULL)
	{
		printf("²åÈëÎ»ÖÃ´íÎó\n");
		return;
	}
	New = BuyNewNode(data);
	New->_pNext = pos;
	New->_pPre = pos->_pPre;
	pos->_pPre->_pNext = New;
	pos->_pPre = New;
}
void DSListErase(Node* _pHead, Node* pos)
{
	assert(_pHead);
	if (pos == NULL)
		return;
	else
	{
		pos->_pPre->_pNext = pos->_pNext;
		pos->_pNext->_pPre = pos->_pPre;
		free(pos);
	}
}
void DSListRemove(Node* _pHead, SDataType data)
{
	assert(_pHead);
	DSListErase(_pHead,DSListFind(_pHead, data));
}
void DSListRemoveAll(Node* _pHead, SDataType data)
{
	assert(_pHead);
	Node* p = _pHead->_pNext;
	while (p != _pHead)
	{
		if (data == p->_data)
		{
			Node* del = p;
			p = p->_pNext;
			DSListErase(_pHead, del);
		}
		else
			p = p->_pNext;
	}
}
void test()
{
	Node* _pHead = NULL;
	DSListInit(&_pHead);
	DSListPushBack(_pHead, 1);
	DSListPushBack(_pHead, 2);
	DSListPushBack(_pHead, 3);
	DSListPushBack(_pHead, 4);
	//DSlistPopBack(_pHead);
	//DSlistPopBack(_pHead);
	//DSlistPopBack(_pHead);
	//DSlistPopBack(_pHead);
	//DSlistPopBack(_pHead);
	//DSListPushBack(_pHead, 4);
	//DSListPushFront(_pHead, 1);
	//DSListPushFront(_pHead, 2);
	//DSListPushFront(_pHead, 3);
	//DSListPushFront(_pHead, 4);
	DSListInsert(DSListFind(_pHead, 2), 9);
	DSListInsert(DSListFind(_pHead, 4), 0);
	DSListPrint(_pHead);
	DSListErase(_pHead, DSListFind(_pHead, 2));
	DSListErase(_pHead, DSListFind(_pHead, 4));
	DSListPrint(_pHead);
	DSListDestroy(&_pHead);
}

void test1()
{
	Node* _pHead = NULL;
	DSListInit(&_pHead);
	DSListPushBack(_pHead, 1);
	DSListPushBack(_pHead, 2);
	DSListPushBack(_pHead, 3);
	DSListPushBack(_pHead, 4);
	DSListPushBack(_pHead, 3);
	DSListPushBack(_pHead, 3);
	DSListPrint(_pHead);
	DSListRemove(_pHead, 2);
	DSListPrint(_pHead);
	DSListRemoveAll(_pHead, 3);
	DSListPrint(_pHead);
	DSListDestroy(&_pHead);
}