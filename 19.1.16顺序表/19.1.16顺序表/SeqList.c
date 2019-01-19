#include"SeqList.h"
void PrintSeqList(SeqList pc)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->arr[i]);
	}
	printf("\n");
}
void SeqListInit(SeqList pc)
{
	assert(pc);
	pc->capacity = 3;
	pc->arr = (DataType*)malloc(sizeof(DataType) * pc->capacity);
	if (pc->arr == NULL)
	{
		assert(0);
		return;
	}
	pc->size = 0;
}
void CheckCapacity(SeqList pc)
{
	assert(pc);
	if (pc->size == pc->capacity)
	{
		DataType* str = (DataType*)realloc(pc->arr,sizeof(DataType)*(pc->capacity + 2));
		if (str == NULL)
		{
			assert(0);
			return;
		}
		pc->arr = str;
		str = NULL;
		pc->capacity = pc->capacity + 2;
	}
}
void SeqListDestroy(SeqList pc)
{
	assert(pc);
	if (pc->arr != NULL)
	{
		free(pc->arr);
		pc->arr = NULL;
		pc->capacity = 0;
		pc->size = 0;
	}
}
void SeqListPushBack(SeqList pc,DataType data)
{
	assert(pc);
	CheckCapacity(pc);
	pc->arr[pc->size] = data;
	pc->size++;
}
void SeqListPopBack(SeqList pc)
{
	assert(pc);
	if (pc->size != 0)
	{
		pc->size--;
	}
}
void SeqListPushFront(SeqList pc, DataType data)
{
	assert(pc);
	CheckCapacity(pc);
	int i = 0;
	for (i = pc->size - 1; i >= 0; i--)
	{
		pc->arr[i + 1] = pc->arr[i];
	}
	pc->arr[0] = data;
	pc->size++;
}
void SeqListPopFront(SeqList pc)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size-1; i++)
	{
		pc->arr[i] = pc->arr[i + 1];
	}
	pc->size--;
}
void SeqListInsert(SeqList pc, DataType pos, DataType data)
{
	assert(pc);
	if (pos<0 || pos>pc->size)
	{
		printf("插入位置错误\n");
		return;
	}
	CheckCapacity(pc);
	int i = 0;
	for (i = pc->size-1; i>=pos; i--)
	{
		pc->arr[i + 1] = pc->arr[i];
	}
	pc->arr[pos] = data;
	pc->size++;
}
void SeqListErase(SeqList pc, DataType pos)
{
	assert(pc);
	if (pos < 0 || pos >= pc->size)
	{
		printf("删除位置错误\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->size - 1; i++)
	{
		pc->arr[i] = pc->arr[i+1];
	}
	pc->size--;
}
int SeqListFind(SeqList pc, DataType data)
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (data == pc->arr[i])
		{
			return i;
		}
	}
	return -1;
}
void SeqListMove(SeqList pc, DataType data)
{
	assert(pc);
	int i = 0;
	int pos = 0;
	pos=SeqListFind(pc, data);
	if (pos != -1)
	{
		for (i = pos; i < pc->size - 1; i++)
		{
			pc->arr[i] = pc->arr[i + 1];
		}
		pc->size--;
	}
	else
		printf("要移除的元素不存在\n");
}
void SeqListRemove(SeqList pc, DataType data)
{
	assert(pc);
	int pos = 0;
	int i = 0;
	for (i = 0; i < pc->size - 1; i++)
	{
		int j = 0;
		pos = SeqListFind(pc, data);
		if (pos != -1)
		{
			for (j = pos; j < pc->size - 1; j++)
			{
				pc->arr[j] = pc->arr[j + 1];
			}
			pc->size--;
		}
		else
		{
			printf("要移除的元素不存在\n");
			return;
		}
	}
}
int SeqListSize(SeqList pc)
{
	assert(pc);
	return pc->size;
}
int SeqListCapacity(SeqList pc)
{
	assert(pc);
	return pc->capacity;
}
void SeqListEmpty(SeqList pc)
{
	assert(pc);
	pc->size = 0;
}
int SeqListGetFront(SeqList pc)
{
	assert(pc);
	return pc->arr[0];
}
int SeqListGetBack(SeqList pc)
{
	assert(pc);
	return pc->arr[pc->size - 1];
}