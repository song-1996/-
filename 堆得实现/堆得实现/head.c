#include"heap.h"

#if 0
int Greater(HDatatype e1, HDatatype e2)
{
	return e1 > e2 ? 1 : 0;
}
int Less(HDatatype e1, HDatatype e2)
{
	return e1 < e2 ? 1 : 0;
}
void Print(Heap* hp)
{
	assert(hp);
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->array[i]);
	}
	printf("\n");
}
void swap(HDatatype* a,HDatatype* b)
{
	HDatatype tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustUp(Heap* hp, int i)
{
	assert(hp);
	int child = i;
	int parent = (child - 1) / 2;
	while (parent>=0)
	{
		if (hp->cmp(hp->array[child+1] , hp->array[child])&&child<hp->size-1)
		{
			child++;
		}
		if (hp->cmp(hp->array[child], hp->array[parent]))
		{
			swap(&hp->array[parent], &hp->array[child]);
		}
		else
			break;
		child=parent;
		parent=(child-1)/2;
	}
}
void AdjustDown(Heap* hp, int i)
{
	assert(hp);
	int parent = i;
	int child = parent * 2 + 1;
	while (child < hp->size)
	{
		if (hp->cmp(hp->array[child + 1], hp->array[child]) && child < hp->size - 1)
		{
			child++;
		}
		if (hp->cmp(hp->array[child], hp->array[parent]))
		{
			swap(&hp->array[parent], &hp->array[child]);
		}
		else
			break;
		parent = child;
		child = parent * 2 + 1;
	}
}
void CreatHeap(Heap* hp, int arr[], int size,pf Cmp)
{
	assert(hp);
	hp->array = (HDatatype*)malloc(sizeof(HDatatype)*size);
	if (NULL == hp->array)
	{
		return;
	}
	hp->size = 0;
	hp->capacity = size;
	hp->cmp = Cmp;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		hp->array[hp->size] = arr[i];
		hp->size++;
	}
	for (i = ((hp->size-1)-1)/2; i>=0; i--)
	{
		AdjustDown(hp, i);
	}
}
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->array != NULL)
	{
		free(hp->array);
		hp->capacity = 0;
		hp->size = 0;
	}
}
void Check_capacity(Heap* hp)
{
	assert(hp);
	if (hp->size >= hp->capacity)
	{
		HDatatype* str = (HDatatype*)malloc(sizeof(HDatatype)*(hp->capacity + 2));
		if (str == NULL)
		{
			return;
		}
		memcpy(str, hp->array, hp->size * sizeof(HDatatype));
		hp->array = str;
		str = NULL;
		hp->capacity = hp->capacity + 2;
	}
}
void InsertHeap(Heap* hp, HDatatype data)
{
	assert(hp);
	Check_capacity(hp);
	hp->array[hp->size] = data;
	hp->size++;
	AdjustUp(hp, hp->size - 1);
}
void EraseHeap(Heap* hp)
{
	assert(hp);
	if (hp->size == 0)
	{
		return;
	}
	swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp,0);
}

int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->size;
}

int EmptyHeap(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
void SortHeap(Heap* hp)
{
	assert(hp);
	int n = hp->size;
	while (hp->size - 1)
	{
		swap(&hp->array[0], &hp->array[hp->size - 1]);
		hp->size--;
		AdjustDown(hp, 0);
	}
	hp->size = n;
}

#endif 
int Greater(HDataType e1, HDataType e2)
{
	return e1 > e2 ? 1 : 0;
}
int Less(HDataType e1, HDataType e2)
{
	return e1 < e2 ? 1 : 0;
}
void Print(Heap* h)
{
	assert(h);
	int i = 0;
	for (i = 0; i < h->size; i++)
	{
		printf("%d ", h->array[i]);
	}
	printf("\n");
}
void swap(HDataType* a, HDataType* b)
{
	HDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustUp(Heap* h, int i)
{
	assert(h);
	int child = i;
	int parent = (child - 1) / 2;
	while (parent>=0)
	{
		if (child+1  < h->size && h->cmp(h->array[child] , h->array[child+1]))
		{
			child = child + 1;
		}
		if (h->cmp(h->array[parent] , h->array[child]))
		{
			swap(&h->array[parent], &h->array[child]);
		}
		else
			return;
		child = parent;
		parent = (child - 1) / 2;
	}
}
void AdjustDown(Heap* h, int i)
{
	assert(h);
	int parent = i;
	int child = parent * 2 + 1;
	while (child<h->size)
	{
		if (child+1  < h->size && h->cmp(h->array[child], h->array[child + 1]))
		{
			child = child + 1;
		}
		if (h->cmp(h->array[parent], h->array[child]))
		{
			swap(&h->array[parent], &h->array[child]);
		}
		else
			return;
		 parent = child;
		 child = parent * 2 + 1;
	}
}
void Check_Capacity(Heap* h)
{
	assert(h);
	if (h->size == h->capacity)
	{
		int newcapacity = 2 * h->capacity;
		HDataType* ptr = (HDataType*)malloc(sizeof(HDataType)*newcapacity);
		if (ptr == NULL)
		{
			return;
		}
		int i = 0;
		for (i = 0; i < h->size; i++)
		{
			ptr[i] = h->array[i];
		}
		free(h->array);
		h->array = ptr;
		h->capacity = newcapacity;
	}
}
void CreatHeap(Heap* h, int* arr, int size,pf cmp)
{
	assert(h);
	int i = 0;
	h->array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (h->array == NULL)
	{
		return;
	}
	h->size = 0;
	h->capacity = size;
	h->cmp = cmp;
	for (i = 0; i < size; i++)
	{
		h->array[h->size++] = arr[i];
	}
	for (i = (h->size-2)/2; i >= 0; i--)
	{
		AdjustDown(h, i);
	}
}
void InsertHeap(Heap* h, HDataType data)
{
	assert(h);
	Check_Capacity(h);
	h->array[h->size++] = data;
	AdjustUp(h, h->size - 1);
}
void EraseHeap(Heap* h)
{
	assert(h);
	swap(&h->array[0], &h->array[h->size - 1]);
	h->size--;
	AdjustDown(h,0);
}
int size(Heap* h)
{
	assert(h);
	return h->size;
}
int empty(Heap* h)
{
	assert(h);
	return h->size == 0;
}
void DestroyHeap(Heap* h)
{
	assert(h);
	if(h->array)
	{
		free(h->array);
		h->capacity = 0;
		h->size = 0;
	}
}