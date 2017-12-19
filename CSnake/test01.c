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
	struct Student s;
	strcpy(s.name, "dwefwe");
	s.age = 1;
	s.score = 13;
	printf("%s,%d,%d\n",s.name, s.age,s.score);


	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}