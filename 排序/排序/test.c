#include"sort.h"

//int main()
//{
//	int arr[] = { 2,0,4,9,3,6,8,7,1,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	/*InsertSort(arr, sz);*/
//	//ShellSort(arr, sz);
//	/*SelectSort(arr, sz);*/
//	//SelectSortOp(arr,sz);
//	//SelectSortOp1(arr, sz);
//	//HeapSort(arr, sz);
//	//BubbleSort(arr, sz);
//	/*QuickSort(arr,0,sz);*/
//	/*MergeSort(arr,sz);*/
//	//PcountSort(arr, sz);
//	MergeSortNor(arr, sz);
//	Print(arr, sz);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void swap(int* m, int *n)
//{
//	int tmp = *m;
//	*m = *n;
//	*n = tmp;
//}
void print(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//int PartSort1(int *a, int left, int right)//左右指针法 
//{
//	int key = a[right];
//	int keyindex = right;
//	while (left < right)
//	{
//		//left找大，right找小，再交换（右边为k,左边先走；左边为k，右边先走）
//		while (left < right&&a[left] <= key)
//			++left;
//		while (left < right&&a[right] >= key)
//			--right;
//		if (left < right)
//		{
//			swap(&a[left], &a[right]);
//			++left;
//			--right;
//		}
//	}
//	swap(&a[left], &a[keyindex]);
//	return left;
//}
//void QuickSort1(int *a, int left, int right)//左右指针法
//{
//	if (left >= right)
//		return;
//	int keyindex = PartSort1(a, left, right);
//	QuickSort1(a, left, keyindex - 1);
//	QuickSort1(a, keyindex + 1, right);
//
//}

void Test8()
{
	int a[50];
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
			a[i] = rand() % 50 + 1;
		printf("排序前:");
		print(a, 10);
		MergeSort(a,10);
		printf("排序后:");
		print(a, 10);
	}
	//printf("排序前:");
	//print(a, 10);
	//MergeSort(a, 10);
	//printf("排序后:");
	//print(a, 10);
}
int main()
{
	srand((unsigned long)time(NULL));
	Test8();
	return 0;
}