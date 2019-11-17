#include"Queue.h"
Node* BuyNode(int data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_next = NULL;
	return NewNode;
}
void InitQueue(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
void DestroyQueue(Queue* q)
{
	assert(q);
	Node* Del = q->front;
	while (q->front)
	{
		q->front = Del->_next;
		free(Del);
		Del = q->front;
	}
	q->front = NULL;
}
void Push(Queue* q, QDataType data)
{
	Node* New = NULL;
	assert(q);
	New = BuyNode(data);
	if (q->front == NULL)
	{
		q->front = New;
		q->rear=New;
	}
	else
	{
		q->rear->_next = New;
		q->rear = New;
	}
}
void Pop(Queue* q)
{
	assert(q);
	if (q->front == NULL)
	{
		return;
	}
	else
	{
		Node* del = q->front;
		q->front = q->front->_next;
		free(del);
		del = NULL;
	}
}
int Size(Queue* q)
{
	assert(q);
	Node* cur = q->front;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
int Empty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}
QDataType Front(Queue* q)
{
	assert(q);
	return q->front->_data;
}
QDataType Rear(Queue* q)
{
	assert(q);
	return q->rear->_data;
}
