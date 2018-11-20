#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int length(char *p)
{
	int n;
	for (n = 0;* p != '\0'; p++)
	{
		putchar(*p);
		n++;
	}
	return n;
}

int main()
{
	int len;
	char str[20] = "I come from shanxi!";
	len=length(str);
	printf("\nlen=%d\n", len);
	system("pause");
	return 0;

}