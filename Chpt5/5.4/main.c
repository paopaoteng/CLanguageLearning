#include<stdio.h>
#include"memory.h"

int main()
{
	char *a,*b;
	a =	alloc(10001);
	b = alloc(10);
	printf("a = %0x b = %0x\n",(int)a, (int)b);
	return 0;
}


