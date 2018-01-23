#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void to_binary(unsigned int value, char buf[], int num_of_bits)
{
	for (int i = 0; i < num_of_bits; i++)
	{
		unsigned int mask = 1 << (num_of_bits - 1 - i);
		if (value & mask)
		{
			buf[i] = '1';
		}
		else {
			buf[i] = '0';
		}
	}
	buf[num_of_bits] = 0;
}

int main(void) {

	char buf[33];
	
	for (int i = 1; i < 20; i++)
	{
		to_binary(i, buf, (int)(log2(i) + 1));
		printf("%d--%s--\n", (int)(log2(i) + 1), buf);
	}

	system("pause");//暂停	#include<stdlib.h>
					//2.ctrl+f5
	return 0;
}