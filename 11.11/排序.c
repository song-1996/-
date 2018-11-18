#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10];
	int i, j, t,k;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 4; i++)
	{
		k = i;
		for (j = i+1; j < 5; j++)
		{
			if (a[k] > a[j])
				k = j;
			if (k!=i)
			{
				t = a[k];
				a[k] = a[i];
				a[i] = t;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}