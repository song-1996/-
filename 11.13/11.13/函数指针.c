#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int add(int c, int d)
{
	int s=0;
	s = c +	d;
	return s;
}

int add1(int e, int(*p)(int a ,int b))
{
	int sum;
	sum = e + (*p)(a, b);
}
int main()
{
	int a = 4, b = 5;
	int e = 6;
	int (*p)(int,int);
	p = add;
	int s = add1(e, add);
	printf("%d\n", s);
	system("pause");
	return 0;

}