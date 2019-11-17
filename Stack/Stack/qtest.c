#include"Queue.h"
int main()
{
	Queue q;
	InitQueue(&q);
	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Push(&q, 4);
	int size = Size(&q);
	int empty = Empty(&q);
	int front = Front(&q);
	int rear = Rear(&q);
	printf("%d %d\n", size, empty);
	printf("%d %d\n", front, rear);
	DestroyQueue(&q);
	system("pause");
	return 0;

}