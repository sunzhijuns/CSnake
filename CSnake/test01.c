#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void normal_func()
{
	int i = 0;
	++i;
	printf("i = %d\n", i);
}

void static_func()
{
	//1、在main调用之前，就已经分配空间，就已经初始化
	//2、整个程序结束，static局部变量才会释放
	//3、static局部变量只能用常量初始化
	//4、还叫局部变量，站在作用域角度看，i只能在{}内部直接使用
	static int i = 10;//这句话没效果，只在第一次人为初始化时调用
	++i;
	printf("i = %d\n", i);

	//int a = 0; // 只有在函数调用时，执行到这句话才分配空间
	//static int j = a;//j在main调用之前，就已经分配空间，就已经初始化
	static int m;
	m = 1;

}

int main(void) {
	//普通局部变量，通常放在某个函数，某个语句，某个{}里面
	//程序执行到定义语句时，才会给a分配空间
	//离开{}，a自动回收，释放，所谓释放，不是空间消失，这个空间用户不能再用
	//局部变量，不初始化，值为垃圾数据，随机数，不同编译器值不一样
	{
		int a = 10;
		for (size_t i = 0; i < 2; i++)
		{

		}
		//int b;
		//printf("b = %d\n", b);
	}

	normal_func();
	normal_func();
	normal_func();

	static_func();
	static_func();
	static_func();

	



	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}

/*
普通局部变量
	1）系统维护内存，自动分配空间，自动释放，自动变量，不认为初始化，值为垃圾数
static局部变量
	1）在main函数调用前，已经分配空间，已经初始化，不认为初始化，自动赋值为0；
	2）整个程序结束后，static局部变量才会释放

*/