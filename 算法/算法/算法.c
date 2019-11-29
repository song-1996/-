#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Perm(int *arr,int k,int n)
{
	int i = 0;
	int j = 0;
	int* temparr = (int*)malloc(sizeof(int)*n);
	if (temparr == NULL)
	{
		return;
	}
	memcpy(temparr, arr, sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		swap(&arr[k], &arr[i]);
		for (j = 0; j < n; j++)
		{
			printf("%d", arr[j]);
		}
		printf("\n");
		swap(&arr[k + 1], &arr[k + 2]);
		for (j = 0; j < n; j++)
		{
			printf("%d", arr[j]);
		}
		printf("\n");
		memcpy(arr, temparr, sizeof(int)*n);
	}
	free(temparr);
	temparr = NULL;
}
int main()
{
	int arr[] = { 1,2,3,4 };
	Perm(arr,0 ,4);
	system("pause");
	return 0;

}