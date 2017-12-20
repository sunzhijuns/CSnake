#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Info {
	int age;
	char sex;
	char name[50];
};
struct Student
{
	//嵌套结构体变量，不能是本结构体变量
	//struct Student temp;//err struct Student类型不确定，内存大小无法确定
	//可以起嵌套任何类型的结构体指针变量
	struct Student * next;// 因为指针大小确定，32位系统4字节大小，64位系统8字节大小
	struct Info info;
	int score;
};//有分号

int main(void) {

	struct Student s = { 0 };
	printf("%p,%d,%c,%s,%d\n",s.next, s.info.age, s.info.sex, s.info.name, s.score);

	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}