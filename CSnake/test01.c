#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Student 标识符，用户自定义的名字
//定义一个结构体类型，struct Stdent ，合起来才是类型名
//成员变量不能直接赋值
struct Student
{
	char name[50];
	int age;
	int score;
};//有分号

int main(void) {

	//类型 变量名
	//Student s;//c++可以，c语言不行

	struct Student a[] =
	{
		{0},
		{0},
		{"ss",22,33},
	};
	int n = sizeof(a) / sizeof(a[0]);
	printf("n = %d\n", n);

	for (size_t i = 0; i < 3; i++)
	{
		//printf("%s,%d,%d\n", (a + i)->name, (a + i)->age, (a + i)->score);
		//printf("%s,%d,%d\n", (&a[i])->name, (&a[i])->age, (&a[i])->score);
		//printf("%s,%d,%d\n", (*(a+i)).name, (*(a + i)).age, (*(a + i)).score);
		printf("%s,%d,%d\n", a[i].name, a[i].age, a[i].score);
	}



	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}