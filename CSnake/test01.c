#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

	//1、数组在{}内部定义，不初始化，值为随机数
	int a[3][4];
	//2、全部初始化，一维数组初始化方式
	int b[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };


	//3、分段初始化，全部初始化，看方便，写麻烦
	int c[3][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	//4、部分初始化，第一个[]的元素的个数可以不指定
	int d[][4] = {1,2,3,4,5,6,7,8,9,10,};
	//5、所有元素都清零
	int e[3][4] = { {0},{1} };

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			printf("a[%d,%d]=%d,", i, j, e[i][j]);
		}
		printf("\n");

	}
	
	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}