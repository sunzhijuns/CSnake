#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<conio.h>//_getch(),_kbhit
#include<Windows.h>//Sleep()

int main(void) {

	//1、设置一个种子
	//srand(100);
	srand(time(NULL));
	//2、生成随机数
	int i = 0;
	int num;
	for ( i = 0; i < 10; i++)
	{
		num = rand();
		printf("%d\n", num);

	}
	char ch = _getch();
	printf("%d,%c\n", ch, ch);

	while (1)
	{
		while (_kbhit())
		{

			printf("有键盘按下\n");
			Sleep(1000);
		}
	}

	return 0;
}
