#include"Stack.h"
void Check_Capacity(Stack* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newcapacity = 2 * s->capacity;
		SDataType* ptr = (SDataType*)malloc(sizeof(SDataType)*newcapacity);
		if (ptr == NULL)
		{
			return;
		}
		memcpy(ptr, s->arr, sizeof(SDataType)*s->size);
		free(s->arr);
		s->arr = ptr;
		s->capacity = newcapacity;
	}
}
void InitStack(Stack* s)
{
	assert(s);
	s->arr = (SDataType*)malloc(sizeof(SDataType)*3);
	if (s->arr == NULL)
	{
		return;
	}
	s->size = 0;
	s->capacity = 3;
}
void DestroyStack(Stack* s)
{
	assert(s);
	if (s->arr)
	{
		free(s->arr);
		s->arr = NULL;
		s->size = 0;
		s->capacity = 0;
	}
}
void PushStack(Stack* s, SDataType data)
{
	assert(s);
	Check_Capacity(s);
	s->arr[s->size] = data;
	s->size++;
}
void PopStack(Stack* s)
{
	assert(s);
	if(s->size!=0)
	s->size--;
}
int SizeStack(Stack* s)
{
	assert(s);
	return s->size;
}
int Capacity(Stack* s)
{
	assert(s);
	return s->capacity;
}
SDataType GetTopStack(Stack* s)
{
	assert(s);
	return s->arr[s->size-1];
}
int EmptyStack(Stack* s)
{
	assert(s);
	return s->size == 0;
}