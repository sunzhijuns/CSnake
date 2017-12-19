#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

	{
		/*
		野指针
		1、定义变量，&变量，这些都是合法地址，也叫合法指针
		2、通过malloc()等堆区分配空间返回的地址，也是合法地址
		3、除了1、2，非法地址，野地址，野指针
		*/
		int a = 10;
		int * p;//未初始化，为 野指针
				//*p = &a;// 这句话导致内存问题，操作野指针所指向的内存
		p = &a;
	
	}

	{
		/*
		1、所谓的空指针，只是为了做一个标志
		2、给这个指针变量赋值为NULL，NULL就是数字0
		*/
		int * p = NULL;

		if (p == NULL)//说明这个指针，没有使用
		{
			int a = 10;
			p = &a;
		}

		// 不要操作空指针所指向的空间
		int * tmp = NULL;
		//*temp = 111; // 空指针只是做标志位，标志这个变量没有人用
	}

	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}