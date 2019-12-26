#include"Stack.h"
void InitStack(Stack* ps)
{
	assert(ps);
	ps->arr = (SDataType*) malloc(sizeof(SDataType) * 5);
	if (ps->arr == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = 5;
}
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SDataType* ptr = (SDataType*)malloc(sizeof(SDataType)*(ps->capacity + 3));
		if (ptr == NULL)
		{
			return;
		}
		memcpy(ptr, ps->arr, sizeof(SDataType)*ps->size);
		ps->arr = ptr;
		free(ptr);
		ptr = NULL;
		ps->capacity = ps->capacity + 3;
	}
}
void PushStack(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->arr[ps->size] = data;
	ps->size++;
}
void PopStack(Stack* ps)
{
	assert(ps);
	if (ps->size == 0)
		return;
	else
	{
		ps->size--;
	}
}
int SizeStack(Stack* ps)
{
	assert(ps);
	return ps->size;
}
int EmptyStack(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}
int CapacityStack(Stack* ps)
{
	assert(ps);
	return ps->capacity;
}
SDataType GetTopStack(Stack* ps)
{
	assert(ps);
	return ps->arr[ps->size - 1];
}
void DestroyStack(Stack* ps)
{
	assert(ps);
	if (ps->arr != NULL)
	{
		free(ps->arr);
		ps->size = 0;
		ps->capacity = 0;
		ps->arr = NULL;
	}
}