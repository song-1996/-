#define _CRT_SECURE_NO_WARNINGS 1
<<<<<<< HEAD
#include"game.h"
void menu()
{
	printf("****************\n");
	printf("**** 1.play ****\n");
	printf("**** 0.exit ****\n");
	printf("****************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	Init(board, ROW, COL);
	display_board(board, ROW, COL);
	while (1)
	{
		player(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C' )
			break;
		display_board(board, ROW, COL);
		computer(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		display_board(board, ROW, COL);
	}
	if (ret == 'X')
	{
		printf("玩家赢\n");
	}
	else
		if (ret == '#')
		{
			printf("电脑赢\n");
		}
		else
			if (ret == 'Q')
			{
				printf("平局\n");
			}
	display_board(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("选择错误，请重新输入!\n");
			break;
		}
	} while (input);
=======
#include<stdio.h>
#include<stdlib.h>
int main()
{	  
  /*__|___|___ 	
	__|___|___
	  |   |   */
	int i = 0;
	int j = 0;
	int a[3][3] = {0};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %c  ", a[3][3]);
			if (j < 2)
				printf("|");
		}
		printf("\n");
		if (i < 2)
		{
			for (j = 0; j < 3; j++)
			{
				printf("---");
				if (j < 2)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
>>>>>>> 2709c4781aad33e8a1c26a03f8a6e222631a9ca6
	system("pause");
	return 0;

}