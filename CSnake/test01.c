#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

	double score[3][5] = 
	{
		88,77,99,59,77,
		95,97,91,98,90,
		65,55,84,57,81
	};
	double sum[3] = { 0.0 };
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			sum[i] += score[i][j];
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		printf("average:%.2lf\n", sum[i] / 5);
	}

	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}