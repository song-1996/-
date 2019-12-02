#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int i = 0;
	int count = 0;
	scanf("%d %d", &num1, &num2);
	while (i < 32)
	{
		num1=num1 >> 1;
		num2=num2 >> 1;
		int p1 = num1 & 1;
		int p2 = num2 & 1;
		if (p1 != p2)
		{
			count++;
		}
		i++;
	}
	printf("%d \n", count);
	system("pause");
	return 0;

}