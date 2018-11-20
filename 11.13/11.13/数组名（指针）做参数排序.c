#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void px(int *b, int n);

int main()
{
	int a[8] = { 3,5,4,6,8,7,9,11 };
	int i;
	int *p = a;
	px(p, 8);
	for (i = 0; i < 8; i++)
		printf("%3d", a[i]);
	printf("\n");

	system("pause");
	return 0;

}

void px(int *b, int n)
{	
	int i, j;
	for (i=0; i < 7; i++)
		for (j = 0; j < 8 - i - 1; j++)
		{
			if (*(b+j) > *(b+j+1))
			{
				int t;
				t = *(b+j);
				*(b + j) = *(b + j + 1);
				*(b + j + 1) = t;
			}
		}
}
