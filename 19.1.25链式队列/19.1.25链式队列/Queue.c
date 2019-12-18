#include"Queue.h"
Node* BuyQueueNode(QDataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode->data = data;
	NewNode->pNext = NULL;
	return NewNode;
}
void QueueInit(Queue* pc)
{
	assert(pc);
	pc->front = pc->rear = NULL;
}
void QueuePush(Queue* pc,QDataType data)
{
	Node* new = NULL;
	assert(pc);
	new = BuyQueueNode(data);
	if (pc->front == NULL)
	{
		pc->front = pc->rear = new;
	}
	else
	{
		pc->rear->pNext = new;
		pc->rear = new;
	}
}
void QueuePop(Queue* pc)
{
	Node* del = NULL;
	assert(pc);
	if (pc->front == NULL)
		return;
	else if (pc->front == pc->rear)
	{
		free(pc->front);
		pc->front = NULL;
	}
	else
	{
		del = pc->front;
		pc->front = del->pNext;
		free(del);
	}
}
QDataType QueueFront(Queue* pc)
{
	assert(pc);
	return pc->front->data;
}
QDataType QueueRear(Queue* pc)
{
	assert(pc);
	return pc->rear->data;
}
int QueueSize(Queue* pc)
{
	assert(pc);
	Node* p = pc->front;
	int count = 0;
	while (p)
	{
		count++;
		p = p->pNext;
	}
	return count;
}
int QueueEmpty(Queue* pc)
{
	assert(pc);
	return pc->front == NULL;
}
void QueueDestroy(Queue* pc)
{
	assert(pc);
	Node* p = pc->front;
	while (p)
	{
		Node* del = p;
		p = p->pNext;
		free(del);
	}
}


void test()
{
	Queue s;
	QueueInit(&s);
	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
	printf("%d %d\n",QueueFront(&s),QueueRear(&s));
	QueuePop(&s);
	QueuePop(&s);
	printf("%d %d\n", QueueSize(&s), QueueEmpty(&s));
	QueuePop(&s);
	printf("%d %d\n", QueueSize(&s), QueueEmpty(&s));
	QueuePop(&s);
	QueueDestroy(&s);
}