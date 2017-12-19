#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

	//1、在32位编译器下，指针大小都是32位（4字节）
	//1、在64位编译器下，指针大小都是64位（8字节）
	printf("%d,%d,%d\n", sizeof(char *), sizeof(int ******), sizeof(double *));
	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}