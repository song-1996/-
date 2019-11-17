#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch = 0;
	while ((ch=getchar())!= EOF)
	{
		if (ch >= 'a'&&ch <= 'z')
		{
			ch = ch - 32;
		}
		else
			if (ch >= 'A'&&ch <= 'Z')
			{
				ch = ch + 32;
			}
			else
				if (ch >= '0' && ch <= '9')
				{
					continue;
				}
		putchar(ch);
	}
	system("pause");
	return 0;

}