#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Student
{
	char name[50];
	int age;
	int score;
}Student;//有分号

//从左往右，const修饰最近的字符，这里修饰的是*
//指针所指向的内存（成员变量）不能改变，指针变量可以改变
void func(const Student * p)
//void func (Student const * p) 等价
{
	//p->age = 18;//err
	p = NULL;//ok
}


//从左往右，const修饰最近的字符，这里修饰的是p
//指针所指向的内存（成员变量）可以改变，指针变量不可以改变
void func1(Student * const p)
{
	p->age = 18;//ok
	//p = NULL;//err
}

//从左往右，const修饰最近的字符
//指针所指向的内存（成员变量）不可以改变，指针变量不可以改变
void func1(const Student * const p)
{
	//p->age = 18;//err
	//p = NULL;//err
}
int main(void) {

	system("pause");//暂停	#include<stdlib.h>
	//2.ctrl+f5
	return 0;
}