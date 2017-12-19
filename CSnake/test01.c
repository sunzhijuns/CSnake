#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	/*
	1、定义一个一维数组，多少维就有多少[]
	2、[]数字代表数组元素个数
	3、定义数组时，[]数字最好是常量
	4、数组名在同一个{}作用域，名字要唯一
	5、访问数组元素，下标引用，a[0]~a[9],记得从0开始，没有a[10],操作不能越界
	*/
	int a[10];
	/*
	6、访问数组元素，通过下标引用，[]内部可以是变量、常量、表达式。
	*/
	int j = 2;
	a[j] = 3; // a[2]=3，下标是变量
	a[j + 1] = 4; //a[2+1]=4，下标是表达式

	for (size_t i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		printf("a[%d]=%d\n", i, a[i]);
	}

	
	//int n = 10;
	//int b[n];//c99标准可以


	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}