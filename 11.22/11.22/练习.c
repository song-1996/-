#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int i = 0;
//	int a = 0;
//	for (i = 0; i < 5; i++)
//	{
//		 a = rand()%10+1;    
//		 printf("%d \n", a);
//	}
//	system("pause");
//	return 0;
//
//}
//#include<math.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 100; i < 1000; i++)
//	{
//		int len = i;
//		int lenth = 1;
//		while (len = len / 10)
//		{
//			lenth++;
//		}
//			sum = 0;
//			int t = i;
//			while (t > 0)
//			{
//
//				int a = t % 10;
//				sum = sum + pow(a, lenth);
//				t = t / 10;
//			}
//			if (i == sum)
//				printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int input=0;
//	int i = 0;
//	int min = 0;
//	int min_next = 0;
//	scanf("%d %d", &min,&min_next);
//	if (min > min_next)
//	{
//		min = min ^ min_next;
//		min_next = min ^ min_next;
//		min = min ^ min_next;
//	}
//	for (i = 0; i < 8; i++)
//	{
//		scanf("%d", &input);
//		if (input < min)
//		{
//			//先把最小值赋给次小值
//			//再把输入的值赋给最小值
//			//这两个赋值式顺序不能调换
//			min_next = min;
//			min = input;
//		}
//		else
//			//不能写数学式min<input<min_next
//		if ( (input>min) && (input < min_next))
//		{
//			min_next = input;
//		}
//	}
//	printf("min=%d min_next=%d\n", min, min_next);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	/*int n=0;
//	scanf("%d", &n);
//	int a = 0;
//	while (n > 0)
//	{
//		a=n % 10;
//		printf("%d \n", a);
//		n=n / 10;
//	}*/
//	system("pause");
//	return 0;
//}
int is_prime(int n)
{
	int i = 0;
	for (i = 2; i <= (n / 2); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;

}
int main()
{
	int len2 = 0;
	int j = 0;
	int input = 0;
	int i = 0;
	int len1 = 0;
	int prime1 = 0;
	int prime2 = 0;
	scanf("%d", &input);
	if (is_prime(input) == 1)
		printf("%d \n", input);
	else
	{
		for (i = input + 1; i < 1000; i++)
		{
			if (is_prime(i) == 1)
			{
				len1 = i - (input + 1);
				prime1 = i;
				break;
			}
		}
		for (j = input - 1; j > 0; j--)
		{
			if (is_prime(j) == 1)
			{	
				len2 = (input - 1) - j ;
				prime2 = j;
				break;
			}
		}
		if (len1 < len2)
			printf("%d \n", prime1);
		else
			printf("%d \n", prime2);
	}

	system("pause");
	return 0;
}