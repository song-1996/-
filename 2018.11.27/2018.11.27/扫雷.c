#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("*** 1.play  0.exit ***\n");
	printf("**********************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	printf("\n");
	Init(mine, ROWS, COLS, '0');
	set_mine(mine, ROW, COL);
	display(mine, ROW, COL);
	printf("\n");
	Init(show, ROWS, COLS, '*');
	display(show, ROW, COL);
	find_mine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，请重新输入:\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;

}