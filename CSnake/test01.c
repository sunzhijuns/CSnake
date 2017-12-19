#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * func()
{
	int a = 10;
	/*
	func调用完毕，a自动释放，所谓释放，不是空间消失，
	a的空间被系统回收，用户不能操作

	*/
	return &a;
}

int * func1()
{
	int a = 10;
	return a;
}

int main(void) {
	

	int * p;
	p = func();
	*p = 111;//内存出问题
	int a = func1();
	int b = func1();
	int c = a + b;
	printf("%d,%d\n", *p,c);


	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}