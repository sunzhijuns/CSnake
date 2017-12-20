#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1、定义在函数外部的变量就是全局变量
2、全局变量，任何地方都能使用
3、在main函数调用前，已经分配空间，已经初始化，不人为初始化，自动赋值为0
4、整个程序结束后，全局变量才会释放
*/


int main(void) {


	/*
	3、使用这个全局变量时，如果定义不在前面，需要声明
	4、所谓的声明，告诉编译器，这个变量有定义的，只是放在了别的地方定义
	*/

	extern int a, b;
	printf("a=%d,b=%d\n", a, b);

	extern void func();

	func();
	



	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}


//可以在定义时同时初始化，在函数外部，不能单独给局部变量赋值
int a = 1;
//a = 1;//err

int b;
b = 2;//ok


void func()
{
	printf("a=%d,b=%d\n", a, b);//前面能找到a,b的定义无需声明
}