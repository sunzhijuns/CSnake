#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*

在C中，调用函数时，前面没有定义，别的地方有定义，不用声明，可以调用，有警告
在c++中，调用函数时，前面没有定义，别的地方有定义，需要声明后，才可调用
*/
int main(void) {
	printf("%d\n", strlen("abc"));
	return 0;
}
