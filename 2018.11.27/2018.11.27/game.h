#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define mine_sum 10

void Init(char board[ROWS][COLS], int rows, int cols, char set);
void display(char board[ROWS][COLS], int row, int col);
void set_mine(char mine[ROWS][COLS], int row, int col);
void find_mine(char mine[ROWS][COLS], char show[ROWS][ROWS], int row, int col);