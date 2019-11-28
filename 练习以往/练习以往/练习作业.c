#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int count_ones(unsigned int vaule)
//{
//	int i = 1;
//	int count=0;
//	unsigned int ret = 0;
//	while (i <= 32)
//	{
//
//		if (i == 1)
//		{
//			 ret = vaule;
//		}
//		if ((ret & 1) == 1)
//			count++;
//		ret = vaule >> i;
//		//00001111
//		//000001111
//			i++;
//	}
//	return count;
//}
//int main()
//{
//	int a = 15;
//	int sum = count_ones(a);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//
//}
//
//int main()
//{
//	int a = 15;
//	//00000000000000000000000000001111
//	int i = 0;
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 14;
//	//1110
//	//1010
//	//1010+0100>>1
//	//1010+0010
//	//10+2
//	int b = 10;
//	int sum = (a&b)+((a^b)>>1);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4,5,8,1,2,3,4 };
//	int b[100] = { 0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		b[a[i]] = b[a[i]] + 1;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if((b[a[i]])==1)
//			printf("%d \n",a[i]);
//	}
//	system("pause");
//	return 0;
//}


//char* reserve(char* left, char* right)
//{
//	char* str = left;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//	return str;
//}
//char* reserve_end(char* s, int count)
//{
//	char* ret = s;
//	char* left = s;
//	char* right = s + count - 1;
//	reserve(left,right);
//	while (*s!='\0')
//	{
//		char* start = s;
//		while ((*s != ' ')&&(*s!='\0'))
//		{
//			s++;
//		}
//		reserve(start, s - 1);
//		if(*s!='\0')
//		s++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "student a am i";
//	int len = sizeof(arr) / sizeof(arr[0]) - 1;
//	reserve_end(arr, len);
//	system("pause");
//	return 0;
//}

//char* reserve(char* str, int count)
//{
//	char* ret = str;
//	char* left =str;
//	char* right = str + count - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//	return ret;
//}
//char* reserve_end(char* arr)
//{
//	char* ret = arr;
//	while (*arr != '\0')
//	{
//		char* start = arr;
//		/*int count = 0;*/
//		while ((*arr != ' ') && (*arr != '\0'))
//		{
//			arr++;
//			/*count++;*/
//		}
//		int count = arr - start;
//		reserve(start, count);
//		if (*arr != '\0')
//		arr++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "student a am i";
//	int len = sizeof(arr) / sizeof(arr[0]) - 1;
//	reserve(arr,len);
//	reserve_end(arr);
//	system("pause");
//	return 0;
//}
//void ji_ou(int *arr, int sz)
//{
//	int* left = arr;
//	int* right = arr+(sz-1);
//	while (left < right-1)
//	{
//
//		if ((*left) % 2 != 0)
//			left++;
//		if ((*right) % 2 == 0)
//			right--;
//		if ((*left) % 2 == 0 && (*right) % 2 != 0)
//		{
//			int tmp=*left;
//			*left = *right;
//			*right = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = {7,8,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	ji_ou(arr,sz);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,3,3,4,2,6,5,5,7,2 };
//	int i = 0;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left < right-1)
//	{
//		if (arr[left] % 2 != 0)
//			left++;
//		if (arr[right] % 2 == 0)
//			right--;
//		if (arr[left] % 2 == 0 && arr[right] % 2 != 0)
//		{
//			int tmp = 0;
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//
//}
