#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

	//1、如果数组在{}，定义时不初始话，它的值为随机数（不同的编译器结果不一样）
	int a[10];
	//2、全部初始化，每个元素都赋值，只有定义，才可以同时初始化，否则只能一个一个元素赋值
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };// 只能少，不能多
	//3、部分初始化，没有初始化的元素自动赋值为0
	int c[10] = { 1,2,3,4 };
	//4、把所有元素初始化为0
	int d[10] = {0};//只有d[0]赋值为0，其他为自动填0
	//5、数组定义同时初始化，第一个[]的数字不写，编译器根据初始化的元素个数确定大小
	int e[] = { 1,2,3,4,5,6,7,8,9,10 };
	//sizeof是运算符，测数据类型大小
	printf("sizeof(e) = %d\n", sizeof(e)/sizeof(int));
	for (size_t i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n", i, e[i]); 
	}

	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}