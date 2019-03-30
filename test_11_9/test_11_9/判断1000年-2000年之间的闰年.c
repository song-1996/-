#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n ;
	int k=0;
	for (n = 1000; n <= 2000; n++)
	{
		if (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0))
		{
			printf("%6d",n);
			k = k++;
			if (k % 10 == 0)
				printf("\n");
		
		}
		
	}
	printf("\n");
	system("pause");
	return 0;

}