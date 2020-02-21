#include"ListNode.h"

ListNode* BuyNewNode(NDataType data)
{
	ListNode* NewNode =(ListNode*) malloc(sizeof(ListNode));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_next = NULL;
	return NewNode;
}
void InitListNode(ListNode** pl)
{
	assert(pl);
	*pl = NULL;
}
//void InitListNode(ListNode** pl)
//{
//	assert(pl);
//	*pl = BuyNewNode(0);
//}
void DestroyListNode(ListNode** pl)
{
	assert(pl);
	if ((*pl) == NULL)
		return;
	ListNode* Del = (*pl);
	while ((Del)->_next)
	{
		(*pl) = Del->_next;
		free(Del);
		Del = (*pl);
	}
	free(Del);
	(*pl) = NULL;
}
void PushBack(ListNode** pl, NDataType data)
{
	ListNode* New = NULL;
	assert(pl);
	New = BuyNewNode(data);
	if ((*pl) == NULL)
	{
		(*pl) = New;
	}
	else
	{
		ListNode* cur = (*pl);
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = New;
	}
}
void PopBack(ListNode** pl)
{
	assert(pl);
	if ((*pl) == NULL)
		return;
	if ((*pl)->_next == NULL)
	{
		free(*pl);
		*pl = NULL;
	}
	else
	{
		ListNode* Pre = NULL;
		ListNode* cur = (*pl);
		while (cur->_next)
		{
			Pre = cur;
			cur = cur->_next;
		}
		free(cur);
		cur = NULL;
		Pre->_next = NULL;
	}
}

void PushFront(ListNode** pl, NDataType data)
{
	ListNode* New = NULL;
	assert(pl);
	New = BuyNewNode(data);
	if ((*pl) == NULL)
	{
		(*pl) = New;
	}
	else
	{
		New->_next = (*pl);
		(*pl) = New;
	}
}
void PopFront(ListNode** pl)
{
	assert(pl);
	if ((*pl) == NULL)
		return;
	if ((*pl)->_next == NULL)
	{
		free(*pl);
		*pl = NULL;
	}
	else
	{
		ListNode* Del = (*pl);
		(*pl) = (*pl)->_next;
		free(Del);
		Del = NULL;
	}
}

void SListInsertAfter(ListNode* pos, NDataType data)
{
	if (pos == NULL)
		return;
	else
	{
		ListNode* New = BuyNewNode(data);
		New->_next = pos->_next;
		pos->_next=New;
	}
	
}
void SListErase(ListNode** pl, ListNode* pos)
{
	assert(pl);
	if (pos == NULL)
		return;
	else
		if (pos == (*pl))
		{
			ListNode* Del = (*pl);
			(*pl) = (*pl)->_next;
			free(Del);
		}
	else
	{
		ListNode* cur = (*pl);
		ListNode* pre = (*pl);
		while (cur)
		{
			if (pos == cur)
			{
				pre->_next = pos->_next;
				free(pos);
				pos = NULL;
				return;
			}
			pre = cur;
			cur = cur->_next;
		}
	}
}
ListNode* SListFind(ListNode** pl, NDataType data)
{
	assert(pl);
	if ((*pl) == NULL)
		return NULL;
	ListNode* cur = (*pl);
	while (cur)
	{
		if (cur->_data == data)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

int SListSize(ListNode** pl)
{
	assert(pl);
	ListNode* cur = (*pl);
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
int SListEmpty(ListNode**  pl)
{
	return (*pl) == NULL;
}
ListNode* SListFront(ListNode**  pl)
{
	if ((*pl) == NULL)
		return NULL;
	return (*pl);
}
ListNode* SListBack(ListNode**  pl)
{
	if ((*pl) == NULL)
		return NULL;
	else
		if ((*pl)->_next == NULL)
			return (*pl);
	else
	{
		ListNode* cur = (*pl);
		while (cur->_next)
		{
			cur = cur->_next;
		}
		return cur;
	}
}
void SListRemove(ListNode**  pl, NDataType data)
{
	assert(pl);
	if ((*pl) == NULL)
		return;
	if ((*pl)->_data == data)
	{
		ListNode* Del = (*pl);
		(*pl) = (*pl)->_next;
		free(Del);
		Del = NULL;
	}
	else
	{
		ListNode* pre = (*pl);
		ListNode* cur = (*pl);
		while (cur)
		{
			if (cur->_data == data)
			{
				pre->_next = cur->_next;
					free(cur);
					cur = NULL;
					return;
			}
			pre = cur;
			cur = cur->_next;
		}

	}
}
int Loop_Count(ListNode* pHead)
{
	int count = 2;
	ListNode* p1 = pHead;
	ListNode* p2 = pHead->_next;
	if (p2)
		p1 = p2->_next;
	while (p1 != p2)
	{
		p2 = p2->_next;
		if (p2)
			p1 = p2->_next;
		if (p1 == NULL)
			return -1;
	}
	p1 = p1->_next;
	while (p1 != p2)
	{
		count++;
		p1 = p1->_next;
	}
	return count;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (!pHead)
		return NULL;
	int n = Loop_Count(pHead);
	if (n == -1)
		return NULL;
	ListNode* p1 = pHead;
	ListNode* p2 = pHead;
	while (n--)
		p1 = p1->_next;
	while (p1 != p2)
	{
		p1 = p1->_next;
		p2 = p2->_next;
	}
	return p1;
}
void SListRemoveAll(ListNode**  pl, NDataType data);

////////////////////////////////////////////////////////////////////////

/*
ListNode* swapPairs(ListNode** head) 
{
	if (*head == NULL || (*head)->_next == NULL)
		return *head;
	ListNode* tmp = (*head)->_next;
	(*head)->_next = swapPairs(&(tmp->_next));
	tmp->_next = *head;
	return tmp;
}
*/

ListNode* swapPairs(ListNode** head)
{
	if (!(*head) || !((*head)->_next))
		return (*head);
	ListNode* tmp = (*head)->_next;
	ListNode* pre = (*head);
	ListNode* pre_p = NULL;
	(*head) = tmp;
	while (tmp)
	{
		pre->_next = tmp->_next;
		pre_p = pre;
		tmp->_next = pre;
		pre = pre->_next;
		if (pre)
			tmp = pre->_next;
		else
			tmp = pre;
		if (tmp)
			pre_p->_next = tmp;
		else
			pre_p->_next = pre;
	}
	return (*head);
}