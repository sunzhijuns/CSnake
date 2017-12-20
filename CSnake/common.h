#pragma once

#define CHAR_WALL '*'//墙
#define CHAR_HEAD '@'//蛇头
#define CHAR_BODY '#'//蛇的身体
#define CHAR_FOOD '%'//食物
#define CHAR_NULL '_'

//方向键
//#define UP 72
//#define DOWN 80
//#define LEFT 75
//#define RIGHT 77
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

//声明一个全局的二维数组
#define ROW 15
#define COL 15

extern char game[ROW][COL];

//移动在控制台屏幕上的坐标
extern void gotoxy(int x, int y);
