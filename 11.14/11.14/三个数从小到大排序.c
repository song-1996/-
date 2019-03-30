#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	int a = 20, b = 30, c = 10;
	printf("a=%d b=%d c=%d\n",a,b,c);
	int t = 0;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("a=%d b=%d c=%d\n",a,b,c);
	system("pause");
	return 0;

}