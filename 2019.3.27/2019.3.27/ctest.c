#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
int main()
{
	int arr[10] = {2,3,4,5,1,10,9,8,6,7};
	int i = 0;
	int max = arr[0];
	int maxpos = 0;
	int min = arr[0];
	int minpos = 0;
	for (i = 1; i < 9; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			maxpos = i;
		}
		if (min > arr[i])
		{
			min = arr[i];
			minpos = i;
		}
	}
	if (arr[maxpos] > arr[0])
		swap(&arr[maxpos], &arr[0]);
	if (arr[minpos] < arr[i])
		swap(&arr[minpos], &arr[i]);
	arr[maxpos] = max;
	arr[minpos] = min;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}
*/

/*
int main()
{
	int arr[10] = { 2,3,4,5,1,10,9,8,6,7 };
	int i = 0;
	int arr1[20] = { 0 };
	for (i = 0; i < 10; i++)
	{
		arr1[i] = arr[i];
	}
	for (i = 0; i < 10; i++)
	{
		arr1[10 + i] = arr[i];
	}
	for (i = 10-4; i < 20-4; i++)
	{
		arr[i - 6] = arr1[i];
	}
	system("pause");
	return 0;
}
*/

//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int k = 0;
//	int count = 0;
//	for (i = 0; 1; i++)
//	{
//		if (i == sz)
//			i = 0;
//		if (arr[i] != 0)
//			k++;
//		else
//			continue;
//		if (k % 3 == 0)
//		{
//			arr[i] = 0;
//			count++;
//		}
//		if (count == sz - 1)
//			break;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d\n", i + 1);
//		}
//	}
//	system("pause");
//	return 0;
//}

/*
int main()
{
	int i = 0;
	int n = 0;
	int sz = 0;
	int arr[100] = { 0 };
	int j = 0;
	while (1)
	{
		int f1 = 1, f2 = 1, f3 = 1;
		int sum = 0;
		scanf("%d", &n);
		if (n == 0)
		{
			sz = j;
			break;
		}
		if (n == 1 )
			arr[j++] = 1;
		else if (n == 2)
			arr[j++] = 2;
		else if (n == 3)
			arr[j++] = 3;
		else
		{
			for (i = 4; i <= n; i++)
			{
				f3 = f1 + f2;
				f1 = f2;
				f2 = f3;
				sum = sum + f3;
			}
			arr[j++] = sum+3;
		}
	}
	
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}
*/

int main()
{
	printf("%d\n", -3 % (2));
	system("pause");
	return 0;
}