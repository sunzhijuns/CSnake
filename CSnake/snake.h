#pragma once
typedef struct Point
{
	int x, y;
	struct Point * next;
}Point;
extern void init_snake();
extern void free_snake();

extern int snake_move(char key);
