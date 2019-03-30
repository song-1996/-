#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j;
	int	s = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			s=j * i;
			printf("%d=%d*%d	", s, j, i);
		}

		printf("\n");
	}
	system("pause");
	return 0;

}