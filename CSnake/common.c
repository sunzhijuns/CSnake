//
#include"common.h"
#include<Windows.h>
char game[ROW][COL] = {0};
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);

}