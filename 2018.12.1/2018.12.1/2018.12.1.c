#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#define flag -1
//int main()
//{
//	int input = 0;
//	int count = 0;
//	int sum = 0;
//	int div = 0;
//	printf("请输入成绩:\n");
//	scanf("%d", &input);
//	while (input != flag)
//	{
//		if (input > 0)
//		{
//			count++;
//			sum = sum + input;
//		}
//		scanf("%d", &input);
//	}
//	div = sum / count;
//	printf("%d \n", div);
//	system("pause");
//	return 0;
//
//}

//struct S
//{
//	char arr[100];
//	int age;
//};
//void print(struct S* ps)
//{
//	printf("%s %d\n", ps->arr, ps->age);
//}
//void print1(struct S tmp)
//{
//	printf("%s %d\n", tmp.arr, tmp.age);
//}
//void print2(struct S* ps1)
//{
//	printf("%s %d\n", (* ps1).arr, (* ps1).age);
//}
//int main()
//{
//	struct S ss = { "bit",100 };
//	print(&ss);
//	print1(ss);
//	print2(&ss);
//	printf("%s %d\n", ss.arr, ss.age);
//	system("pause");
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//struct S
//{
//	char sex;
//	struct Stu s;
//};
//int main()
//{
//	struct S ss;
//	scanf("%c", &ss.sex);
//	scanf("%s", &ss.s.name);
//	scanf("%d", &ss.s.age);
//	printf("%c %s %d\n", ss.sex, ss.s.name, ss.s.age);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int n=0;
//	while (n % 2 != 1 || n % 3 != 2 || n % 5 != 4 || n % 6 != 5)
//	{
//		n += 7;
//	}
//	printf("%d \n", n);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d%d", &x, &y);
//	if (x > 0 && y > 0)
//	{
//		printf("在第一象限\n");
//	}
//	else
//	if (x < 0 && y>0)
//	{
//		printf("在第二象限\n");
//	}
//	else
//	if (x < 0 && y < 0)
//	{
//		printf("在第三象限\n");
//	}
//	else
//	if (x > 0 && y < 0)
//	{
//		printf("在第四象限\n");
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if(a + b > c||b+c>a || a+c>b)
//	{
//		if (a == b && b == c)
//		{
//			printf("等边三角形\n");
//		}
//		else
//			if (a == b ||a==c || b==c)
//			{
//				printf("等腰三角形\n");
//			}
//			else
//			{
//				printf("一般三角形\n");
//			}
//	}
//	else
//	{
//		printf("%d %d %d不能构成三角形\n", a, b, c);
//	}
//	system("pause");
//	return 0;
//}
#include<string.h>
int main()
{
	char arr1[20] = "abcdef";
	char arr2[20] = { "********" };
	int i = 0;
	int j = 0;
	for (i = 0; arr1[i] != '\0'; i++)
	{
		arr2[i] = arr1[i];
	}
	arr2[i] = arr1[i];
	for (j = 0; j <= i; j++)
	{
		printf("%c", arr2[j]);
	}
	system("pause");
	return 0;
}