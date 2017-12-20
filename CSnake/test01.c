#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




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
		int b;
		printf("b = %d\n", b);
	}
	



	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}