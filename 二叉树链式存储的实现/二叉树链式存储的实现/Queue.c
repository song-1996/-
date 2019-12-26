#include"Stack.h"
Node* BuyNewNode(QDataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
void InitQueue(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	Node* NewNode = NULL;
	assert(q);
	NewNode = BuyNewNode(data);
	if (q->front == NULL)
	{
		q->front=q->rear = NewNode;
	}
	else
	{
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
}
void QueuePop(Queue* q)
{
	Node* Del = NULL;
	assert(q);
	if (q->front == NULL)
		return;
	else
		if (q->front == q->rear)
		{
			free(q->front);
			q->front = NULL;

		}
		else
		{
			Del = q->front;
			q->front = Del->next;
			free(Del);
		}
}
int QueueSize(Queue* q)
{
	assert(q);
	Node* pcur = q->front;
	int count = 0;
	while (pcur)
	{
		pcur = pcur->next;
		count++;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
QDataType QueueRear(Queue* q)
{
	assert(q);
	return q->rear->data;
}
void DestroyQueue(Queue* q)
{
	assert(q);
	Node* pcur = q->front;
	if (pcur)
	{
		Node* del = pcur;
		pcur = pcur->next;
		free(del);
	}
}