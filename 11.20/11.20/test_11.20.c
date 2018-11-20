#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n%j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main() 
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n");
//	printf("sum=%d \n", count);
//
//	system("pause");
//	return 0;
//
//}
//int is_leap_year(int year)
//{
//	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (is_leap_year(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////形参x,y只是实参a,b的复制，
////在函数内部交换x,y的值，
////不会改变a,b的值
//void swap(int x, int y)
//{
//	int t = 0;
//	t = x;
//	x = y;
//	y = t;
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	printf("a=%d b=%d\n", a, b);
//	swap(a, b);
//	printf("a=%d b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//void swap(int *p1, int *p2)
//{
//	int t = 0;
//	t = *p1;
//	*p1 = *p2;
//	*p2 = t;
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	printf("a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	system("pause");
//	return 0;
//}

//最大公约数greatest common divisor
//int output_gcd(int a,int b)
//{
//	int z = 0;
//	if (a < b)
//	{
//		int t = 0;
//		t = a;
//		a = b;
//		b = t;
//	}
//	do {
//		z = a % b;
//		a = b;
//		b = z;
//	} while (z != 0);
//	return a;
//}
//int main()
//{
//	int a = 12;
//	int b = 18;
//	int z = 0;
//	int gcd = output_gcd(a, b);
//	printf("%d ", gcd);
//	printf("\n");
//	system("pause");
//	return 0;
//}return 0;

//int is_include_9(int n)
//{
//	int units = 0;
//	int tens = 0;
//	int hundreds = 0;
//	units = n % 10;
//	tens = n / 10 % 10;
//	hundreds = n / 100;
//	if (units == 9 || tens == 9 || hundreds == 9)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int units = 0;
//	int tens = 0;
//	int hundreds = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (is_include_9(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//int search_x(int key, int left, int right, int a[])
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (a[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			if (a[mid] > key)
//			{
//				right = mid - 1;
//			}
//			else
//				return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(a)/sizeof(a[0])-1;
//	int mid = 0;
//	int key = 20;
//	mid=search_x(key,left, right, a);
//	printf("%d ", mid);
//	printf("\n");
//	system("pause");
//	return 0;
//}