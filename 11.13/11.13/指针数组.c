#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[7] = { 1,2,3,4,5,6,7 };
	int i;
	int *p[7];
	for (i = 0; i < 7; i++)
	{
		p[i] = &a[i];
		
		printf("%2d", *p[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}