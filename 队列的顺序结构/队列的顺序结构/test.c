#include"queue.h"
int main()
{
	Queue q;
	InitQueue(&q);
	PushQueue(&q, 1);
	PushQueue(&q, 2);
	PushQueue(&q, 3);
	PushQueue(&q, 4);
	PushQueue(&q, 5);
	PushQueue(&q, 5);
	PushQueue(&q, 5);
	printf("%d %d\n", empty(&q), length(&q));
	printf("%d %d\n", front(&q), rear(&q));
	Print(&q);
	PopQueue(&q);
	PopQueue(&q);
	PushQueue(&q, 6);
	PushQueue(&q, 7);
	PushQueue(&q, 8);
	printf("%d %d\n", empty(&q), length(&q));
	printf("%d %d\n", front(&q), rear(&q));
	Print(&q);
	DestroyQueue(&q);
	system("pause");
	return 0;

}