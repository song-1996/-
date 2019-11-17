#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("************\n");
	printf("** 1.play **\n");
	printf("** 0.exit **\n");
	printf("************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int n=0;
	while (1)
	{
		printf("请输入你猜的数字:");
		scanf("%d", &n);
		if (ret > n)
		{
			printf("你猜小了\n");
		}
		else
			if (ret < n)
			{
				printf("你猜大了\n");
			}
			else
			{
				printf("你猜对了\n");
				break;
			}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("请选择>?");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;

}