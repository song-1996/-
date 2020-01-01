#include"SequenList.h"
void InitSequenList(SequenList* sq)
{
	assert(sq);
	sq->arr = (SDataType*)malloc(sizeof(SDataType) * 3);
	if (sq->arr == NULL)
	{
		return;
	}
	sq->size = 0;
	sq->capacity = 3;
}

void CheckCapacity(SequenList* sq)
{
	assert(sq);
	if (sq->size == sq->capacity)
	{
		int* ptr = (SDataType*)malloc(sizeof(SDataType)*(sq->capacity * 2));
		if (ptr == NULL)
		{
			return;
		}
		memcpy(ptr, sq->arr, sizeof(SDataType)*sq->capacity);
		free(sq->arr);
		sq->arr = ptr;
		ptr = NULL;
		sq->capacity = sq->capacity * 2;
	}
}
void PushSequenList(SequenList* sq, SDataType data)
{
	assert(sq);
	CheckCapacity(sq);
	sq->arr[sq->size] = data;
	sq->size++;
}
void PopSequenList(SequenList* sq)
{
	assert(sq);
	if (sq->size == 0)
		return;
	sq->size--;
}
void DestroySequenList(SequenList* sq)
{
	assert(sq);
	if (sq->arr != NULL)
	{
		free(sq->arr);
		sq->arr = NULL;
		sq->size = 0;
		sq->capacity = 0;
	}
}

SDataType GetMax(SequenList* sq)
{
	assert(sq);
	int i = 0;
	int max = sq->arr[0];
	for (i = 1; i < sq->size; i++)
	{
		if (max < sq->arr[i])
		{
			max = sq->arr[i];
		}
	}
	return max;
}
int GetMaxPos(SequenList* sq)
{
	assert(sq);
	int i = 0;
	int max = 0;
	for (i = 1; i < sq->size; i++)
	{
		if (sq->arr[max] < sq->arr[i])
		{
			max = i;
		}
	}
	return max;
}

void PushSequenListX(SequenList* sq, SDataType data, int pos)
{
	assert(sq);
	CheckCapacity(sq);
	int i = 0;
	for (i = sq->size-1; i>=pos; i--)
	{
		sq->arr[i+1] = sq->arr[i];
	}
	sq->arr[pos] = data;
	sq->size++;
}