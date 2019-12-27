#include"sort.h"

void Print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void merge(int* arr, int left, int mid, int right,int* tmp)
{
	int left2 = mid;
	int left1 = left;
	while (left1 < mid&&left2 < right)
	{
		if (arr[left1] <= arr[left2])
			tmp[left++] = arr[left1++];
		else
			tmp[left++] = arr[left2++];
	}
	while (left1 < mid)
		tmp[left++] = arr[left1++];
	while (left2 < right)
		tmp[left++] = arr[left2++];
}
void _MergeSort(int* arr, int left,int right,int* tmp)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		_MergeSort(arr, left, mid, tmp);
		_MergeSort(arr, mid, right, tmp);
		merge(arr, left, mid, right, tmp);
		for (int i = left; i < right; i++)
			arr[i] = tmp[i];
	}
}
void MergeSort(int* arr, int sz)
{
	int left = 0;
	int right = sz;
	int* tmp = (int*)malloc(sizeof(arr[0])*sz);
	if (tmp == NULL)
		return;
	_MergeSort(arr, left, right,tmp);
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}


//int _QuickSort(int* arr,int left,int right)
//{
//	right = right - 1;
//	int end = right;
//	int tmp = arr[right];
//	while(left < right)
//	{
//		while (arr[left] <= tmp && left < right)
//			left++;
//		while (arr[right] >= tmp && left < right)
//			right--;
//		if (left < right)
//			swap(&arr[left], &arr[right]);
//	}
//	swap(&arr[right], &arr[end]);
//	return left;
//}

//int _QuickSort(int* arr, int left, int right)
//{
//	right = right - 1;
//	int key = arr[right];
//	while(left < right)
//	{
//		while (arr[left] <= key && left<right)
//			left++;
//			arr[right] = arr[left];	
//		while (arr[right] >= key && left < right)
//			right--;
//			arr[left] = arr[right];
//	}
//	arr[left] = key;
//	return left;
//}

//int _QuickSort(int* arr, int left, int right)
//{
//	int pre = -1;
//	int cur = 0;
//	int key = arr[right - 1];
//	while (cur < right)
//	{
//		if (arr[cur]<=key && ++pre!=cur)
//			swap(&arr[pre], &arr[cur]);
//		cur++;
//	}
//	return pre;
//}
//void QuickSort(int* arr,int left ,int right)
//{
//	if (left + 1 < right)
//	{
//		int mid = _QuickSort(arr,left,right);
//		QuickSort(arr, left, mid);
//		QuickSort(arr, mid + 1, right);
//	}
//}
//void InsertSort(int *arr, int sz)
//{
//	int i = 0;
//	int index = 0;
//	for (i = 1; i < sz; i++)
//	{
//		int tmp = arr[i];
//		index = i - 1;
//		while (index>=0 &&arr[index] >tmp)
//		{
//			arr[index+1] = arr[index];
//			index--;
//		}
//		arr[index+1] = tmp;
//	}
//}
//void ShellSort(int* arr, int sz)
//{
//	int i = 0;
//	int gap = 3;
//	while (gap)
//	{
//		for (i = gap ; i < sz; i++)
//		{
//			int tmp = arr[i];
//			int idx = i-gap ;
//			while (idx >= 0 && tmp < arr[idx])
//			{
//				arr[idx + gap] = arr[idx];
//				idx = idx - gap;
//			}
//			arr[idx + gap] = tmp;
//		}
//		gap--;
//	}
//}
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void SelectSort(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int MaxPos = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[MaxPos] < arr[j])
//			{
//				MaxPos = j;
//			}
//		}
//		if(arr[MaxPos]>arr[j])
//		swap(&arr[MaxPos], &arr[j]);
//	}
//}
//void SelectSortOp(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//	if (sz < 4)
//	{
//		InsertSort(arr, sz);
//	}
//	for (i = 0; i < (sz-2)/2; i++)
//	{
//		int MinPos = 1+i;
//		int MaxPos = 1+i;
//		for (j = i+1; j < sz -1-i; j++)
//		{
//			if (arr[MinPos] > arr[j])
//			{
//				MinPos = j;
//			}
//			if (arr[MaxPos] < arr[j])
//			{
//				MaxPos = j;
//			}
//		}
//		if (arr[i] > arr[j])
//			swap(&arr[i], &arr[j]);
//		if(arr[MinPos]<arr[i])
//			swap (&arr[MinPos], &arr[i]);
//		if (arr[MaxPos] > arr[j])
//			swap(&arr[MaxPos], &arr[j]);
//	}
//}
//
//void SelectSortOp1(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz/2; i++)
//	{
//		int MaxPos = i;
//		int MinPos = i;
//		for (j = i; j < sz-i; j++)
//		{
//			if (arr[MaxPos] < arr[j])
//			{
//				MaxPos = j;
//			}
//			if (arr[MinPos] > arr[j])
//			{
//				MinPos = j;
//			}
//		}
//		if (arr[MaxPos] > arr[sz-i-1])
//		{
//			swap(&arr[MaxPos], &arr[sz - i - 1]);
//			if (arr[sz - i - 1] == arr[MinPos])
//				MinPos = MaxPos;
//		}
//
//		if (arr[MinPos] < arr[i])
//		{
//			swap(&arr[MinPos], &arr[i]);
//		}
//	}
//}
//
//void Adjust(int *arr,int sz,int parent)
//{
//	int child = parent * 2 + 1;
//	while (child<sz)
//	{
//		if (child + 1 < sz&&arr[child] < arr[child + 1])
//			child=child+1;
//		if (arr[parent] < arr[child])
//		{
//			swap(&arr[parent], &arr[child]);
//		}
//		else
//			return;
//		parent = child;
//		child = parent * 2 + 1;
//	}
//}
//void HeapSort(int* arr, int sz)
//{
//	//建堆
//	int i = 0;
//	for (i = (sz - 2) / 2; i >= 0; i--)
//	{
//		Adjust(arr, sz, i);
//	}
//	//排序
//	int n = sz;
//	while (n)
//	{
//		swap(&arr[0], &arr[n - 1]);
//		n--;
//		Adjust(arr, n, 0);
//	}
//}
//void BubbleSort(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < sz - 1; i++)
//	{
//		for (j = 1; j < sz; j++)
//		{
//			if (arr[j] < arr[j - 1])
//			{
//				swap(&arr[j], &arr[j - 1]);
//			}
//		}
//	}
//}
//
//int _QuickSort(int* arr, int left,int right)
//{
//	int tmp = arr[right - 1];
//	int sz = right;
//	right = right-1;
//	while (left < right)
//	{
//		while(arr[left] <= tmp&&left<right)
//		{
//			left++;
//		}
//		while (arr[right] >= tmp&&left<right)
//		{
//			right--;
//		}
//		if(left<right)
//		swap(&arr[left], &arr[right]);
//	}
//	if(left>right)
//	swap(&arr[left], &arr[sz-1]);
//	return left;
//}
//
//int _QuickSort1(int* arr, int left, int right)
//{
//	int tmp = arr[right - 1];
//	int sz = right-1;
//	int left1 = left;
//	while (left < sz)
//	{
//		while (arr[left] <= tmp&&left< sz)
//		{
//			left++;
//		}
//		if (left < sz)
//		{
//			arr[sz] = arr[left];
//			sz --;
//		}
//		while (arr[sz] >= tmp && left1 < sz)
//		{
//			sz--;
//		}
//		if (left < sz)
//		{
//			arr[left] = arr[sz];
//			left++;
//		}
//	}
//	arr[left] = tmp;
//	return left;
//}
//
//int _QuickSort2(int* arr, int left, int right)
//{
//	int cur = left;
//	int end = right-1;
//	int prev = left - 1;
//	int tmp = arr[end];
//	while (cur < end)
//	{
//		if (arr[cur] < tmp&&++prev != cur)
//		{
//			swap(&arr[cur], &arr[prev]);
//		}
//		cur++;
//	}
//	swap(&arr[cur], &arr[++prev]);
//	return prev;
//}
//void QuickSort(int* arr, int left,int sz)
//{
//	if (sz-left > 1 )
//	{
//		int p = _QuickSort2(arr, left, sz);
//		QuickSort(arr, left, p);
//		QuickSort(arr, p + 1, sz);
//	}
//}

/*
void merge(int* arr, int left, int mid, int right, int* tmp)
{
	int i = left;//左序列指针
	int j = mid;//右序列指针
	int t = 0;//临时数组指针
	while (i < mid && j < right)
	{
		if (arr[i] <= arr[j])
		{
			tmp[t++] = arr[i++];
		}
		else
		{
			tmp[t++] = arr[j++];
		}
	}
	while (i < mid)
	{//将左边剩余元素填充进tmp中
		tmp[t++] = arr[i++];
	}
	while (j < right)
	{//将右序列剩余元素填充进tmp中
		tmp[t++] = arr[j++];
	}
	t = 0;
	//将tmp中的元素全部拷贝到原数组中
	while (left < right) 
	{
		arr[left++] = tmp[t++];
	}
}
void _MergeSort(int *arr, int left, int right, int* tmp)
{
	if (right-left>1)
	{
		int mid = (left + right) / 2;
		_MergeSort(arr, left, mid, tmp);
		_MergeSort(arr, mid, right, tmp);
		merge(arr, left, mid, right, tmp);
	}
}

void MergeSort(int* arr, int right)
{
	int left = 0;
	int* tmp = (int*)malloc(sizeof(int)*right);
	if (tmp == NULL)
	{
		return;
	}
	memset(tmp, 0, sizeof(int)*right);
	_MergeSort(arr, left, right, tmp);
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}

void PcountSort(int *arr, int sz)
{
	int i = 0;
	int index = 0;
	int count = 0;
	int Minvalue = arr[0];
	int Maxvalue = arr[0];
	for (i = 0; i < sz; i++)
	{
		if (arr[i] > Maxvalue)
		{
			Maxvalue = arr[i];
		}
		if (arr[i] < Minvalue)
		{
			Minvalue = arr[i];
		}
	}
	int range = Maxvalue - Minvalue + 1;
	int* tmp = (int*)malloc(sizeof(int)*range);
	memset(tmp, 0, sizeof(int)*range);
	for (i = 0; i < sz; i++)
	{
		tmp[arr[i]-Minvalue]++;
	}
	for (i = 0; i < range; i++)
	{
		count = tmp[i];
		while (count--)
		{
			arr[index++] = i + Minvalue;
		}
	}
	free(tmp);
	tmp = NULL;
}
void MergeData(int *arr, int left, int mid, int right, int* tmp)
{
		int i = left;//左序列指针
	int j = mid;//右序列指针
	int t = left;//临时数组指针
	while (i < mid && j < right)
	{
		if (arr[i] <= arr[j])
		{
			tmp[t++] = arr[i++];
		}
		else
		{
			tmp[t++] = arr[j++];
		}
	}
	while (i < mid)
	{//将左边剩余元素填充进tmp中
		tmp[t++] = arr[i++];
	}
	while (j < right)
	{//将右序列剩余元素填充进tmp中
		tmp[t++] = arr[j++];
	}
}
void MergeSortNor(int* arr, int sz)
{
	int* tmp = (int*)malloc(sizeof(int)*sz);
	int gap = 1;
	int i = 0;
	while (gap < sz)
	{
		for (i = 0; i < sz; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid > sz)
				mid = sz;
			if (right > sz)
				right = sz;
			MergeData(arr, left, mid, right,tmp);
		}
		memcpy(arr, tmp, sizeof(int)*sz);
		gap = gap * 2;
	}
	free(tmp);
}
*/
//void Merge(int* arr, int left,int mid, int right, int* tmp)
//{
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid;
//	int end2 = right;
//	 int pos = left;
//	while (begin1 < end1 && begin2 < end2)
//	{
//		if (arr[begin1] <= arr[begin2])
//			tmp[pos++] = arr[begin1++];
//		else
//			tmp[pos++] = arr[begin2++];
//	}
//	while (begin1 < end1)
//	{
//		tmp[pos++] = arr[begin1++];
//	}
//	while (begin2 < end2)
//	{
//		tmp[pos++] = arr[begin2++];
//	}
//}
//void _MergeSort(int* arr, int left,int right, int* tmp)
//{
//	if (left + 1 < right)
//	{
//		int mid = (left + right) >> 1;
//		_MergeSort(arr, left, mid, tmp);
//		_MergeSort(arr, mid, right, tmp);
//		Merge(arr, left, mid,right, tmp);
//		memcpy(arr + left, tmp, sizeof(tmp[0])*(right - left));
//	}
//}
//void MergeSort(int* arr, int sz)
//{
//	int* tmp = (int*)malloc(sizeof(arr[0])*sz);
//	if (!tmp)
//		return;
//	int left = 0;
//	int right = sz;
//	_MergeSort(arr, left,right, tmp);
//	if (tmp)
//	{
//		free(tmp);
//		tmp = NULL;
//	}
//}
//
//void MergeSortNor(int* arr, int sz)
//{
//	int* tmp = (int*)malloc(sizeof(int)*sz);
//	int gap = 1;
//	int i = 0;
//	while (gap < sz)
//	{
//		for (i = 0; i < sz; i += 2 * gap)
//		{
//			int left = i;
//			int mid = left + gap;
//			int right = mid + gap;
//			if (mid > sz)
//				mid = sz;
//			if (right > sz)
//				right = sz;
//			Merge(arr, left, mid, right, tmp);
//		}
//		memcpy(arr, tmp, sizeof(arr[0])*sz);
//		gap = gap * 2;
//	}
//	free(tmp);
//}