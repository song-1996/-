#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 18, b = 12;
	printf("a=%d b=%d\n", a, b);
	int z = 0;
	if (a < b)
	{
		int t=0;
		t = a;
		a = b;
		b = t;
	}
	do
	{
		z = a % b;
		a = b;
		b = z;
	} while (z == 0);
	printf("最大公约数=%d\n", b);
	system("pause");
	return 0;

}