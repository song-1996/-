#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char ch1[20] = { "123456" };
	char ch2[20] = { 0 };
	int i = 0;
	while (i<3)
	{
	
		printf("����������:\n");
		scanf("%s", ch2);
		if (strcmp(ch1, ch2) == 0)
		{
			printf("������ȷ\n");
			break;
		}
		else
			printf("�������\n");
		i++;
	}
	if (i >= 3)
	{
		printf("����������������˳�ϵͳ!\n");
	}
	system("pause");
	return 0;

}