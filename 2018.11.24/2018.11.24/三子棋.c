#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{	  
  /*__|___|___ 	
	__|___|___
	  |   |   */
	int i = 0;
	int j = 0;
	int a[3][3] = {0};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %c  ", a[3][3]);
			if (j < 2)
				printf("|");
		}
		printf("\n");
		if (i < 2)
		{
			for (j = 0; j < 3; j++)
			{
				printf("---");
				if (j < 2)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;

}