#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<conio.h>//_getch(),_kbhit
#include<Windows.h>//Sleep()

int main_srand(void) {

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



#include<memory.h> //memset
#include<wchar.h> //wmemset


int main_memset(void) {
	char buffer[] = "This is a test of the memset function";

	printf("sizeof(char) :%d\n", sizeof(char));
	printf("sizeof(int) :%d\n", sizeof(int));
	printf("Before: %s\n", buffer);
	memset(buffer, '*', 3);
	printf("After:  %s\n", buffer);
	return 0;
}

int main_wmemory(void)
{
	wchar_t buffer[] = L"This is a test of the wmemset function";

	wprintf(L"Before: %s\n", buffer);
	wmemset(buffer, '*', 3);
	wprintf(L"After:  %s\n", buffer);
}

int main_unsinged_int(void) {
	int count = 2;

	printf("sizeof(char) :%d\n", sizeof(char));
	printf("sizeof(int) :%d\n", sizeof(int));
	printf("sizeof(unsigned int) :%d\n", sizeof(unsigned int));

	unsigned int * pixels = (unsigned int *)malloc(sizeof(unsigned int *) * count);
	memset(pixels, 0, sizeof(unsigned int) / sizeof(char) * count);
	for (size_t i = 0; i < count; i++)
	{
		printf("%d :--%d--\n", i+1,pixels[i]);
	}
	
}

int main(void) {
	unsigned int MODEL = 0xF;
	unsigned int color = 0x1234;
	unsigned int av = 0;
	printf("MODEL = %p\n", MODEL);

	printf("sizeof(unsigned int) :%d\n", sizeof(unsigned int));

	printf("Before color = %p\n", color);

	av = color & MODEL;
	color >>= 4;
	printf("av = %p\n", av);
	printf("After color = %p\n", color);
	
	return 0;
}
