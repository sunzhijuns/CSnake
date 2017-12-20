
#include"common.h"
#include<string.h>//memset()
#include<stdio.h>
#include<stdlib.h>//srand,rand()
#include<time.h>

static int food_x, food_y;

void init_wall()
{
	memset(game, 0, sizeof(game));	
	int row = 0;
	int col = 0;
	for ( row = 0; row < ROW; row++)
	{
		for ( col = 0; col < COL; col++)
		{
			if (row == 0 || row == ROW - 1 || col == 0 || col == COL-1) {
				game[row][col] = CHAR_WALL;
			}
			else {
				game[row][col] = CHAR_NULL;
			}
		}
	}
}


void draw()
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			printf("%c ", game[row][col]);
		}
		printf("\n");
	}
}


void set(int i, int j,char ch)
{
	game[i][j] = ch;
}

void get(int row, int col)
{
	return game[row][col];
}

//判断蛇是否碰墙，如果碰墙返回1，否则0
int is_touch()
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < ROW; i++)
	{
		for ( j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) {
				if (game[i][j] == CHAR_HEAD)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

void set_food()//设置食物
{
	while (1)
	{
		srand((unsigned int)time(NULL));

		food_x = rand() % (ROW - 2) + 1;
		food_y = rand() % (COL - 2) + 1;

		if (game[food_x][food_y] != CHAR_HEAD && game[food_x][food_y] != CHAR_BODY)
		{
			game[food_x][food_y] = CHAR_FOOD;
			break;
		}
	}
}
int get_food_x()
{
	return food_x;
}
int get_food_y()
{
	return food_y;
}