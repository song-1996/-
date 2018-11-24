#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int count = 0;
//int length(char* p)
//{
//	while (*p != '\0')
//	{
//		count++;//1.2.3.4
//		p++;
//	}
//	return count;
//}
//int main()
//{
//
//	char arr[] = { "abcb" };
//	
//	int len = length(arr);
//	printf("%d \n", len);
//
//	system("pause");
//	return 0;
//
//}
//int length(char *p)
//{
//	while (*p != '\0')
//	{
//		p++;
//		return 1+length(p);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[] = { "abcd" };
//	int len = length(arr);
//	printf("%d \n", len);
//	system("pause");
//	return 0;
//}
//int ret = 0;
//void print(int n)
//{
//		if (n > 9)
//		{
//			print(n/10);
//		}
//		ret=n % 10;
//		printf("%d \n", ret);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	system("pause");
//	return 0;
//}

//int face(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * face(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", face(n));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 0;
//	int face = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		face = face * i;
//	}
//	printf("%d \n", face);
//	system("pause");
//	return 0;
//}
//int fib(int n)
//{
//	int i = 0;
//	int f1 = 1;
//	int f2 = 1;
//	int c = 0;
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		for (i = 3; i <= n; i++)
//		{
//			c = f1 + f2;
//			f1 = f2;
//			f2 = c;
//		}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d \n", fib(n));
//	system("pause");
//	return 0;
//}

//int fib(int n)
//{
//	int f1 = 1;
//	int f2 = 1;
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 2) + fib(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d \n", fib(n));
//	system("pause");
//	return 0;
//}

