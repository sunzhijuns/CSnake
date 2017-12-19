#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	
	int id1 = 1;
	int id2 = 2;
	int id3 = 3;

	int id[10];

	for (size_t i = 0; i < 10; i++)
	{
		id[i] = i + 1;
		printf("id[%d] = %d\n", i, id[i]);
	}
	printf("12345\n");
	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}