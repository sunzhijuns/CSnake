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

	//定义变量同时赋值，叫做初始化
	struct Student s = {"szh",18,100};
	printf("%s,%d,%d\n", s.name, s.age, s.score);

	struct Student s1 = { 0 };
	printf("%s,%d,%d\n", s1.name, s1.age, s1.score);




	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}