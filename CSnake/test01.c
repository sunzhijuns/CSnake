#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int a = 10;

	//1、如果是定义变量，*和类型结合，不是变量结合
	int * p = &a;
	//

	/*
	int * p;
	p = &a;
	*/

	//2、使用变量时，*和变量结合，操作的是指针所指向的内存
	*p = 111; // 操作的不是p的内存，操作的是p所指向的内存，即操作a的内存


	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}