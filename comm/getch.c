#include "getch.h"
#include<stdio.h>
#include<stdlib.h>

static int buf[MAXBUF];
static int pos = 0;

int getch(void)
{
	return pos > 0 ? buf[--pos] : getchar();
}

void ungetch(int c)
{
	if(pos < MAXBUF)
	{
		buf[pos++] = c;
	}
	else
	{
		printf("error: the buffer is fulled\n");
		exit(-1);
	}
}
