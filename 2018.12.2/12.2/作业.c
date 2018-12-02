#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int t = 0;
//void er(int n)
//{
//	if (n > 1)
//	{
//		er(n/2);
//	}
//	t = n % 2;
//	printf("%d ",t);
//}
//int main()
//{
//	int n = 0;
//	int t = 0;
//	printf("请输入一个数:\n");
//	scanf("%d", &n);
//	er(n);
//	system("pause");
//	return 0;
//
//}

//int count = 0;
//int count_one_bits(unsigned int value)
//{
//	int i = 0;
//	while (i < 32)
//	{
//		int t = value & 1;
//		if (t == 1)
//		{
//			count++;
//		}
//		value = value >> 1;
//		i++;
//	}
//	return count;
//}

//int main()
//{
//	int a = 15;
//	count = count_one_bits(a);
//	printf("%d \n", count);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 15;
//	int i = 1;
//	while (i <= 8)
//	{
//		if (i % 2 == 1)
//		{
//			int t = a & 1;
//			printf("奇数位:%d ", t);
//		}
//		if (i % 2 == 0)
//		{
//			int t = a & 1;
//			printf("偶数位:%d ", t);
//		}
//		a = a >> 1;
//		i++;
//		
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 15;
//	int b = 25;
//	int t = 0;
//	int count = 0;
//	t = a ^ b;
//	int i = 1;
//	while (i <= 8)
//	{
//		int k=t & 1;
//		if (k == 1)
//		{
//			count++;
//		}
//		t = t >> 1;
//		i++;
//	}
//	printf("%d \n", count);
//	system("pause");
//	return 0;
//}

