#include<stdio.h>//NULL
#include"snake.h"
#include<stdlib.h>
#include"wall.h"
#include"common.h"
static Point *head = NULL;

static void add_point(int x, int y)
{
	Point * pnew = (Point *)malloc(sizeof(Point));
	pnew->x = x;
	pnew->y = y;
	if (head == NULL)
	{
		head = pnew;
		pnew->next = NULL;
	}
	else {
		set(head->x, head->y, CHAR_BODY);
		pnew->next = head;
		head = pnew;
	}
	set(head->x, head->y, CHAR_HEAD);

}

static void del_point()
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	Point * pre = head;
	Point * tmp = head->next;
	while (tmp->next != NULL)
	{
		pre = pre->next;
		tmp = tmp->next;
	}
	set(tmp->x, tmp->y, CHAR_NULL);
	free(tmp);
	tmp = NULL;
	pre->next = NULL;

}

static void __free_snake(Point * node)
{
	if (node == NULL)
	{
		return;
	}
	else {
		__free_snake(node->next);
		free(node);
		node = NULL;		
	}
}

void free_snake()
{
	//__free_snake(head);
	
	Point * del = head;
	while (del != NULL)
	{
		head = head->next;
		free(del);
		del = head;
	}
	head = NULL;
}

void init_snake()
{
	free_snake();
	add_point(4, 2);
	add_point(4, 3);
	add_point(4, 4);
}

int snake_move(int key)
{
	int i = head->x;
	int j = head->y;
	switch (key)
	{
	case UP: --i;
		break;
	case DOWN: ++i;
		break;
	case LEFT: --j;
		break;
	case RIGHT: ++j;
		break;
	default:
		printf("no dir");
		break;
	}
	if (1==is_touch()|| game[i][j] == CHAR_BODY)
	{
		printf("is_touch || body");
		return 0;
	}
	if (i == get_food_x() && j == get_food_y())
	{
		add_point(i, j);
		set_food();
		return 1;
	}
	else {
		add_point(i, j);
		del_point();
	}
	return 1;
}