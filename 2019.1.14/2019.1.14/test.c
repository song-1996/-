#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//char* fun(char* str,char del)
//{
//	char* ret = str;
//	int len = strlen(str);
//	char* end = str + len - 1;
//	char *s1 = NULL;
//	/*int count = 0;*/
//	while (*str != '\0')
//	{
//		int flag = 0;
//		if (*str == del)
//		{
//			/*count++;*/
//			s1 = str;
//			flag = 1;
//			while (*s1!='\0')
//			{
//				*s1 = *(s1 + 1);
//				s1++;
//			}
//		}
//		if (!flag)
//		str++;
//	}
//	/*str = str - count;
//	*str = '\0';*/
//	return ret;
//}
//int main()
//{
//	char arr[] = "i aa a aaaaaaa";
//	char del = 'a';
//	char* ret = fun(arr,del);
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//
//}

//int main()
//{
//	int a = 1;
//	int b = 2; 
//	int c = 3;
//	int d = 4;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 1; i < 5; i++)
//	{
//
//		for (j = 1; j < 5; j++)
//		{
//			if (i == j)
//				continue;
//			for (k = 1; k < 5; k++)
//			{
//				if (j == k||k==i)
//					continue;
//				{
//					printf("%d %d %d\n", i, j, k);
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
//判断输入的日期是这一年的第几天
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int sum = 0;
//	scanf("%d%d%d", &year, &month, &day);
//		switch (month)
//		{
//		case 1:
//			sum = 0;
//			break;
//		case 2:
//			sum = 31;
//			break;
//		case 3:
//			sum = 59;
//			break;
//		case 4:
//			sum = 90;
//			break;
//		case 5:
//			sum = 120;
//			break;
//		case 6:
//			sum = 151;
//			break;
//		case 7:
//			sum = 181;
//			break;
//		case 8:
//			sum = 212;
//			break;
//		case 9:
//			sum = 243;
//			break;
//		case 10:
//			sum = 273;
//			break;
//		case 11:
//			sum = 304;
//			break;
//		case 12:
//			sum = 334;
//			break;
//		default:
//			printf("输入日期错误\n");
//			break;
//		}
//		if (month < 13 && month>0)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			{
//				if (month > 2)
//					sum = sum + day + 1;
//				sum = sum + day;
//			}
//			else
//			{
//				sum = sum + day;
//			}
//			printf("%d\n", sum);
//		}
//	system("pause");
//	return 0;
//}

//计算这个日期是星期几；
//W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
//int main()
//{
//	int y, m, d,w;
//	scanf("%d%d%d", &y, &m, &d);
//	if (m <= 12 && m >= 1)
//	{
//		if (m <= 2)
//		{
//			m = 12 + m;
//			y--;
//		}
//		w = (d + 2 * m + 3 * (m + 1) / 5 + \
//			y + y / 4 - y / 100 + y / 400) % 7;
//		switch (w)
//		{
//		case 0:
//			printf("星期一\n");
//			break;
//		case 1:
//			printf("星期二\n");
//			break;
//		case 2:
//			printf("星期三\n");
//			break;
//		case 3:
//			printf("星期四\n");
//			break;
//		case 4:
//			printf("星期五\n");
//			break;
//		case 5:
//			printf("星期六\n");
//			break;
//		case 6:
//			printf("星期日\n");
//			break;
//		default:
//			break;
//		}
//	}
//	else
//		printf("输入日期错误\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 8; i ++ )
//	{
//		if (i % 2 == 0)
//		{
//			for (j = 0; j < 8; j++)
//			{
//				if (j % 2 == 0)
//					printf("□"); 
//				else
//					printf("■"); 
//			}
//			printf("\n");
//		}
//		else
//		{
//			for (j = 0; j < 8; j++)
//			{
//				if (j % 2 == 0)
//					printf("■");
//				else
//					printf("□");
//			}
//			printf("\n");
//		}
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int f1 = 1;
//	int f2 = 1;
//	int f3 = 0;
//	int input = 0;
//	int i = 0;
//	scanf("%d", &input);
//	if (input < 3)
//	{
//		f3 = f1;
//	}
//	else
//	{
//		for (i = 3; i <= input; i++)
//		{
//			f3 = f1 + f2;
//			f1 = f2;
//			f2 = f3;
//		}
//	}
//	printf("%d\n", f3);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	printf("%d=",input);
//	int i = 0;
//	for (i = 2; i <= input; i++)
//	{
//		while (input%i == 0)
//		{
//			printf("%d", i);
//			input = input / i;
//			if(input!=1)
//			printf("*");
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 1000; i++)
//	{
//		int sum = 0;
//		for (j = 1; j <= (i / 2); j++)
//		{
//			if (i%j == 0)
//				sum += j;
//		}
//		if (i == sum)
//			printf("%d ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char i, j, k;
//	for (i = 'x'; i <= 'z'; i++)
//	{
//		for (j = 'x'; j <= 'z'; j++)
//		{
//			if(i!=j)
//			for (k = 'x'; k <= 'z'; k++)
//			{
//				if(i!=k&&j!=k)
//				if ((i != 'x') && (k != 'x'&&k != 'z'))
//					printf("a--%c\nb--%c\nc--%c\n", i, j, k);
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
//int age(int n)
//{
//	if (n == 1)
//		return 10;
//	return 2 + age(n - 1);
//}
//int main()
//{
//	int n = 5;
//	printf("%d\n",age(n));
//	system("pause");
//	return 0;
//}