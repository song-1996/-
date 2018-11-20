#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **q;
	int i;
	int a[7] = { 1,2,3,4,5,6,7 };
	int *p[7];
	for (i = 0; i < 7; i++)
	{
		p[i] = &a[i];
		q = &p[i];
		printf("%2d", **q);
	}
	printf("\n");
	system("pause");
	return 0;

}