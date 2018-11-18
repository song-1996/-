#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[2][3];
	int *p;
	//int b[3][2];
	int i, j;
	for (i = 0; i < 2;i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		//	b[j][i] = a[i][j];
		}
	}
	
	p = a;
	for (; p<a[0]+6; p++)
	{
	
		printf("%3d",*p);

	}
	printf("\n");
	system("pause");
	return 0;

}