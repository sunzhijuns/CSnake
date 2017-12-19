#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

	
	int a[10];
	//1、数组名是常量，常量地址，它不允许修改

	//a = 11;
	//100 = 11;

	//2、数组名，它是首元素地址
	//%p以地址的方式打印，16进制方式打印
	printf("a=%p,&a[0]=%p\n", a, &a[0]);

	//3、sizeof()测数组类型的大小，求元素个数
	int b[] = { 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	printf("n=%d\n", sizeof(b) / sizeof(b[0]));

	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}