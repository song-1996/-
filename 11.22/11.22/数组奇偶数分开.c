#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[11] = { 1,3,4,5,6,2,7,8,9,11,13 };
	int arr_1[11] = { 0 };
	int left = 0;
	int i = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	for (i = 0; i < 11; i++)
	{
		if (arr[i] % 2 != 0)
		{
			arr_1[left] = arr[i];
			left++;
		}
		else
		{
			arr_1[right] = arr[i];
			right--;
		}
	}
	for (i = 0; i < 11; i++)
	{
		printf("%d ", arr_1[i]);
	}
	system("pause");
	return 0;

}