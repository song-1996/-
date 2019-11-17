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
	
		printf("请输入密码:\n");
		scanf("%s", ch2);
		if (strcmp(ch1, ch2) == 0)
		{
			printf("密码正确\n");
			break;
		}
		else
			printf("密码错误\n");
		i++;
	}
	if (i >= 3)
	{
		printf("三次密码输入错误，退出系统!\n");
	}
	system("pause");
	return 0;

}