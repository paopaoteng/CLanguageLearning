#include"memory.h"
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(const int n)
{
	if(allocbuf + ALLOCSIZE - allocp >=n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return 0;
	}
}

void afree(char *p)
{
	if(p >= allocbuf && p < allocp + ALLOCSIZE)
	{
		allocp = p;
	}
}
