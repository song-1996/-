#include"Stack1.h"
void CheckCapacity(Stack* ps)
{
	if (ps->top == ps->capacity)
	{
		int new = (ps->capacity) * 2;
		SDatatype* tmp = (SDatatype*)malloc(sizeof(SDatatype)*new);
		if (tmp == NULL)
		{
			assert(0);
			return;
		}
		memcpy(tmp, ps->arr, sizeof(SDatatype)*(ps->capacity));
		free(ps->arr);
		ps->arr = tmp;
		tmp = NULL;
		ps->capacity = new;
	}
}
void StackInit(Stack* ps)
{
	assert(ps);
	ps->arr = (SDatatype*)malloc(sizeof(SDatatype) * 3);
	if (NULL == ps->arr)
	{
		assert(0);
		return;
	}
	ps->capacity = 3;
	ps->top = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->arr != NULL)
	{
		free(ps->arr);
		ps->capacity = 0;
		ps->top = 0;
		ps->arr = NULL;
	}
}
void StackPush(Stack* ps, SDatatype data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->arr[ps->top] = data;
	ps->top++;

}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
		return;
	ps->top--;

}
int StackSize(Stack* ps)
{
	return ps->top;
}
SDatatype StackTop(Stack* ps)
{
	return ps->arr[ps->top-1];
}
int StackEmpty(Stack* ps)
{
	return 0 == ps->top;
}
int StackCapacity(Stack* ps)
{
	return ps->capacity;
}
//int evalRPN(char** tokens, int tokensSize)
//{
//	Stack s;
//	StackInit(&s);
//	int i = 0;
//	for (i = 0; i < tokensSize; i++)
//	{
//		char* str = tokens[i];
//		if ((str[0] != '+') && (str[0] != '-'&&str[1] == '\0') && (str[0] != '*') && (str[0] != '/'))
//		{
//			StackPush(&s, atoi(str));
//		}
//		else
//		{
//			int right = StackTop(&s);
//			StackPop(&s);
//			int left = StackTop(&s);
//			StackPop(&s);
//			switch (str[0])
//			{
//			case '+':
//				StackPush(&s, left + right);
//				break;
//			case '-':
//				StackPush(&s, left - right);
//				break;
//			case '*':
//				StackPush(&s, left*right);
//				break;
//			case '/':
//				StackPush(&s, left / right);
//				break;
//			}
//		}
//	}
//	return StackTop(&s);
//}
//void seck1()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 3);
//	StackPush(&s, 2);
//	StackPush(&s, 4);
//
//	StackPop(&s);
//	StackPop(&s);
//	printf("capacity=%d,size=%d\n", StackCapacity(&s), StackSize(&s));
//	printf("Top=%d,empty=%d\n", StackTop(&s), StackEmpty(&s));
//	StackDestroy(&s);
//}

//MinStack* minStackCreate(int maxSize)
//{
//	MinStack* ms = (MinStack*)malloc(sizeof(MinStack));
//	if (NULL == ms)
//	{
//		assert(0);
//		return NULL;
//	}
//	StackInit(&ms->s1);
//	StackInit(&ms->s2);
//	return ms;
//}
//
//void minStackPush(MinStack* obj, int x)
//{
//	assert(obj);
//	if (StackEmpty(&obj->s1) && StackEmpty(&obj->s2))
//	{
//		StackPush(&obj->s1, x);
//		StackPush(&obj->s2, x);
//	}
//	else
//	{
//		if (x > StackTop(&obj->s2))
//		{
//			StackPush(&obj->s1, x);
//		}
//		else
//		{
//			StackPush(&obj->s1, x);
//			StackPush(&obj->s2, x);
//		}
//	}
//}
//
//void minStackPop(MinStack* obj)
//{
//	assert(obj);
//	if (StackEmpty(&obj->s1) && StackEmpty(&obj->s2))
//		return;
//	if (StackTop(&obj->s1) == StackTop(&obj->s2))
//	{
//		StackPop(&obj->s2);
//		StackPop(&obj->s1);
//	}
//	else
//	{
//		StackPop(&obj->s1);
//	}
//}
//
//int minStackTop(MinStack* obj)
//{
//	return StackTop(&obj->s1);
//
//}
//
//int minStackGetMin(MinStack* obj)
//{
//	return StackTop(&obj->s2);
//
//}
//
//void minStackFree(MinStack* obj)
//{
//	StackDestroy(&obj->s1);
//	StackDestroy(&obj->s2);
//	free(obj);
//	obj = NULL;
//}
//
//
//void test()
//{
//	MinStack* obj=minStackCreate(100);
//	minStackPush(obj, -2);
//	minStackPush(obj, 0);
//	minStackPush(obj, -3);
//	minStackGetMin(obj);
//	minStackPop(obj);
//	minStackTop(obj);
//	minStackGetMin(obj);
//	minStackFree(obj);
//}

MyQueue* myQueueCreate(int maxSize) {
	MyQueue* qs = (MyQueue*)malloc(sizeof(MyQueue));
	if (qs == NULL)
	{
		assert(0);
		return NULL;
	}
	StackInit(&qs->s1);
	StackInit(&qs->s2);
	return qs;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	assert(obj);
	while (!StackEmpty(&obj->s1))
	{
		StackPush(&obj->s2, StackTop(&obj->s1));
		StackPop(&obj->s1);
	}
	StackPush(&obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	assert(obj);
	int ret = 0;
	if (!StackEmpty(&obj->s1) && StackEmpty(&obj->s2))
	{
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	if (!StackEmpty(&obj->s2))
	{
		ret = StackTop(&obj->s2);
		StackPop(&obj->s2);
	}
	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	assert(obj);
	if (!StackEmpty(&obj->s1) && StackEmpty(&obj->s2))
	{
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	return StackTop(&obj->s2);
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
	obj = NULL;
}

void test()
{
	MyQueue* obj = myQueueCreate(50);
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	myQueuePush(obj, 3);
	myQueuePeek(obj);
	myQueueFree(obj);
}