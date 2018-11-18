#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10];
	int *p, i;
	printf("请输入十个数:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	p = a;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");

	for (; p < a + 10; p++)
	{
		printf("%3d", *p);
	}
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		printf("%3d", *(a + i));
	}
	printf("\n");

	for (i = 0,p=a; i < 10; i++)
	{
		printf("%3d", *(p + i));
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d", *p++);
	}
	printf("\n");
	for (i = 0,p=a; i < 10; i++)
	{
		printf("%3d", p[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}