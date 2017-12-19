#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * func()
{
	int * p;
	/*
	1、p指向堆区空间，堆区空间需要调用malloc函数返回
	2、只要程序不结束，用户不free，堆区空间一直存在
	3、int * 指向int，所以，需要分配sizeof(int)大小的空间
	功能：在堆区分配一块连续空间
	参数：需要分配空间的大小
	返回值：成功返回空间的首地址，失败返回NULL
	*/
	p = (int *)malloc(sizeof(int));

	return p;
}

int * func1()
{
	int a = 10;
	return a;
}

int main(void) {
	

	int * p;
	p = func();
	if (p == NULL)//说明分配失败
	{
		printf("p == NULL\n");
		return -1;
	}
	*p = 111;//内存出问题
	int a = func1();
	int b = func1();
	int c = a + b;
	printf("%d,%d\n", *p,c);

	//使用完成，堆区空间需要手动释放
	/*
		1、一夫一妻制，一个malloc一个free
		2、free(p)不是释放p的空间，是释放p所指向的空间
		3、free完的空间，不能在使用，同一块内存只能释放一次
	*/
	free(p);
	p = NULL;


	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}