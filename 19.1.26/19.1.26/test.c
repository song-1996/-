#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int Binsearch(int arr[], int sz,int key)
//{
//	int left = 0;
//	int right = sz;
//	while (left<right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid+1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 1;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int c=Binsearch(arr, sz,key);
//	if (c == -1)
//	{
//		printf("Ã»ÕÒµ½\n");
//	}
//	else
//	{
//		printf("%d\n", c);
//	}
//	system("pause");
//	return 0;
//
//}
#include<assert.h>
#include<string.h>
//int Word_Count(char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str)
//	{
//		if (*str != ' '&&*str != '\0')
//		{
//			count++;
//			while (*str != ' '&&*str != '\0')
//			{
//				str++;
//			}
//		}
//		if(*str!='\0')
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[40] = "a aa  aaa";
//	int len = strlen(arr);
//	int count=Word_Count(arr);
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}

