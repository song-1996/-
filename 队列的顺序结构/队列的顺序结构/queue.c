#include"queue.h"
void Print(Queue* q)
{
	assert(q);
	int i = 0;
	for (i = q->front; i !=q->rear;)
	{
		printf("%d ", q->arr[i]);
		i = (i + 1) % 5;
	}
	printf("\n");
}
void InitQueue(Queue* q)
{
	assert(q);
	q->front = q->rear = 0;
}
void DestroyQueue(Queue* q)
{
	assert(q);
	if (q->arr)
	{
		q->front = q->rear = 0;
	}
}
void PushQueue(Queue* q, QDataType data)
{
	assert(q);
	if ((q->rear+1)%5==q->front)
		return;
	q->arr[q->rear++] = data;
	if (q->rear == 5)
	{
		q->rear = 0;
	}
}
void PopQueue(Queue* q)
{
	assert(q);
	if (q->front==q->rear)
		return;
	q->front++;
	if (q->front == 5)
	{
		q->front = 0;
	}
}
QDataType front(Queue* q)
{
	assert(q);
	return q->arr[q->front];
}
QDataType rear(Queue* q)
{
	assert(q);
	if (q->rear == 0)
		return q->arr[5 - 1];
	else
		return q->arr[q->rear - 1];
}
int empty(Queue* q)
{
	assert(q);
	return (q->rear==q->front);
}
int length(Queue* q)
{
	assert(q);
	return (((q->rear) - (q->front)) + 5) % 5;
}