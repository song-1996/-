#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0,n=0;
	int max = 0;
	scanf("%d", &max);
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &n);
		if (max < n)
		{
			max = n;
		}
	}
	printf("max=%d\n", max);
	system("pause");
	return 0;

}