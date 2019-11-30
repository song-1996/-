#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Init(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int mine1 = 0;
	while (mine1 < mine_sum)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			mine1++;
		}
	}
}
int count_mind(char mine[ROWS][COLS], int x, int y)
{
	int sum = mine[x - 1][y] + mine[x - 1][y - 1] +
		mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
	return sum;

}

void find_mine(char mine[ROWS][COLS],char show[ROWS][ROWS] ,int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win< COL*ROW - mine_sum)
	{
		printf("请输入要排查的坐标>\n");
		scanf("%d%d", &x, &y);
		if ((x < 1 || x>9) || (y < 1 || y>9))
		{
			printf("输入坐标不合法,请重新输入！\n");
		}
		else
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了!\n");
				display(mine, ROW, COL);
					break;
			}
			else
			{
				show[x][y] = count_mind(mine, x, y) + '0';
				display(show, ROW, COL);
				win++;
			}
		}
	}
	if (win == COL*ROW - mine_sum)
	{
		printf("你赢了\n");
		display(mine, ROW, COL);
	}
}