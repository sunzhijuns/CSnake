#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//形参中数组不是数组，是指针变量
/*
下面4中写法完全一样，最后写指针变量的形式
void func(int a[10])
void func(int a[10000])
void func(int a[])
*/
void func(int * a) {
	printf("func sizeof(a) = %d\n", sizeof(a));

	int b = 1;
	a = &b;
	*a = 22;
	printf("b = %d\n", b);
}

int main(void) {

	int a[10] = {1,2,3,4,5,6,7,8,9,0};

	printf("main sizeof(a) = %d\n", sizeof(a));

	func(a);


	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}