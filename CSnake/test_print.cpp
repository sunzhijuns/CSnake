
#include<stdio.h>
int main_0x08x(void)
{
	int a = 0x01020304;
	printf("---%d---\n",sizeof(int));
	printf("GL error after %s(): 0x%08x\n","test",a);
	return 0;
	
}


/*
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER )
一共4步
	1. ( (TYPE *)0 ) 将零转型为TYPE类型指针;
	2. ((TYPE *)0)->MEMBER 访问结构中的数据成员;
	3. &( ( (TYPE *)0 )->MEMBER )取出数据成员的地址;
	4.(size_t)(&(((TYPE*)0)->MEMBER))结果转换类型.巧妙之处在于将0转换成(TYPE*)，
	结构以内存空间首地址0作为起始地址，则成员地址自然为偏移地址；
*/

struct Vertex {
	float pos[2];
	char rgba[4];
};

#define __compiler_offsetof(a,b) __builtin_offsetof(a,b) 

#undef offsetof 
#ifdef __compiler_offsetof 
#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER) 
#else 
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER) 
#endif 


//#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER ) 
int main(void) {

	Vertex * p = 0;
	printf(" pos----%p----\n", &(p->pos));
	printf("rgba----%p----\n", offsetof(Vertex,rgba));

	printf("-----\n");
	
	return 0;
}