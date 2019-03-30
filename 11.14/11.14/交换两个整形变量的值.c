#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=10,b=20;
	printf("a=%d b=%d\n", a, b);
	int t = 0;
	t = a;
	a = b;
	b = t;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;

}