#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

//int main()
//{
//	int a = 25;
//	int i = 0;
//	long long sum = 0;
//	while (i < 32)
//	{
//		int j;
//		long long p = a & 1;
//		if (p != 0)
//		{
//			for (j = 31 - i; j > 0; j--)
//			{
//				p = p * 2;
//			}
//			sum = sum + p;
//		}
//		a=a >> 1;
//		i++;
//	}
//	printf("%lld ", sum);
//	system("pause");
//	return 0;
//
//}

//不使用（a + b） / 2这种方式，求两个数的平均值。

//int add(int x, int y)//①用来实现加法的函数
//{
//	int tmp = 0;
//	do
//	{
//		tmp = x ^ y;
//		y = x & y;
//		x = tmp;
//		y <<= 1;//进位
//	} while (y != 0);
//	return x;
//}
//
//int avg(int x, int y)//②用来求平均值的函数
//{
//	return add(((x^y) >> 1), x&y);
//}
//
//int main()//主函数
//{
//	int a = 0;
//	int b = 0;
//	printf("Input two number:");
//	scanf("%d%d", &a, &b);
//	printf("%d\n", avg(a, b));
//	system("pause");
//	return 0;
//
//}

//编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）

//int main()
//{
//	int arr[5] = { 1,1,2,3,2 };
//	int i = 0;
//	int sum = arr[0];
//	for (i = 1; i < 5; i++)
//	{
//		sum = sum ^ arr[i];
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。


//int main()
//{
//	char arr[] = "student a am i";
//	int right = sizeof(arr) / sizeof(arr[0])-2;
//	int left = 0;
//	while (left <= right)
//	{
//		char tmp=0;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	int i=0;
//	int len = sizeof(arr) / sizeof(arr[0]) - 2;
//	while (i <= len)
//	{
//		if (arr[i] != ' ')
//		{
//			left = i;
//			while (arr[i] && arr[i] != ' ')
//			{
//				i++;
//			}
//			right = i-1;
//		}
//		char tmp = 0;
//		while (left <= right)
//		{
//			char tmp = 0;
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}