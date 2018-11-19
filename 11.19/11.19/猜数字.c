#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***************\n");
	printf("**1.开始游戏***\n");
	printf("**0.退出游戏***\n");
	printf("***************\n");
}
void game(int n)
{
	int input = 0;
	n = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你猜的数字:");
		scanf("%d", &input);
		if (n > input)
		{
			printf("猜小了\n");
		}
		else
			if (n < input)
			{
				printf("猜大了\n");
			}
			else
			{
				printf("猜对了\n");
				break;
			}
	}
}
int main()
{
	int n = 0;
	srand((unsigned)time(NULL));
	menu(n);
again:	
	printf("请选择:");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		game(n);
		break;
	case 0:
		break;
	default:
		printf("选择错误,请重新选择\n");
		goto again;
		break;
	}
	system("pause");
	return 0;

}