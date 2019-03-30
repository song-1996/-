#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0,j=0,n=0;
	int flag = 1;

	for(n=100;n<=200;n++)
	{
		flag = 1;
		for (i = 2; i <= n; i++)
		{
			if (n%i == 0)
			{
				flag = 0;
				break;

			}

		}
		if (flag)
		{
			printf("%5d", n);
			j = j++;
			if (j % 5 == 0)
			printf("\n");
		}

	}
	system("pause");
	return 0;

}