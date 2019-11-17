#include"Stack.h"
int main()
{
	Stack s;
	InitStack(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	int top=GetTopStack(&s);
	printf("%d\n", top);
	PopStack(&s);
	PopStack(&s);
	int size=SizeStack(&s);
	int capacity = Capacity(&s);
	int empty = EmptyStack(&s);
	printf("size=%d capacity=%d empty=%d \n", size,capacity,empty);
	DestroyStack(&s);
	system("pause");
	return 0;

}