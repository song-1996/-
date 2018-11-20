#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void nz(int *b, int n)
{
	int *s,*mid, *end;
	s = b;
	mid = b + n / 2;
	end = b + n - 1;
	for (; b<mid;b++,end--)
	{
		int t;
		t = *b;
		*b = *end;
		*end = t;
	}
}
int main()
{
	int a[7] = {2,3,4,5,6,7,8};
	int i;
	int *p = a;
	nz(p, 7);
	for (i = 0; i < 7; i++)
	{
		printf("%2d", a[i]);
	}
	printf("\n");

	system("pause");
	return 0;

}