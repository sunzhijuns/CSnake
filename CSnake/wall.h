#pragma once
extern void init_wall();//初始化，设置墙壁

extern void draw();//打印数组的每个元素


extern void set(int row, int col, char ch);//

extern void get(int row, int col);

extern int is_touch();//判断蛇是否碰墙，如果碰墙返回1，否则0

extern void set_food();//设置食物

extern int get_food_x();
extern int get_food_y();