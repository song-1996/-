#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int MAX(int *b,int n)
{
	int a[10]={ 1,2,3,4,5,6,7,8,9,10 };
	int max;
	max = *b;
	for (b=a; b< a+10; b++)
	{
		if (max < (*b))
			max = (*b);
	}
	return max;
}
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int max=0;
	max = MAX(a, 10);
	printf("%d\n", max);
	
	system("pause");
	return 0;

}