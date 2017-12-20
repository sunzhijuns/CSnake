#define _CRT_SECURE_NO_WARINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

#include"common.h"

#include"wall.h"
#include"snake.h"


int main(void)
{
	int is_start = 1;// 1代表开始，0代表结束
	int is_dead = 0;//0代表活着，1代表死了
	while (1==is_start)
	{
		is_dead = 0;
		init_wall();
		init_snake();
		set_food();

		//system("cls");
		draw();

		while (0==is_dead)
		{
			printf("wait..\n");
			int key = _getch();
			if (UP != key && DOWN != key && LEFT != key && RIGHT != key)
			{
				continue;
			}
			
			while (0==_kbhit())
			{
				gotoxy(0, 0);
				if (1== snake_move(key))
				{
					draw();
					Sleep(300);
				}
				else {
					is_dead = 1;
					break;
				}
			}
		}



	}
	return 0;
}

int main01(void)
{
	init_wall();

	init_snake();
	set_food();

	draw();

	system("pause");
	return 0;
}