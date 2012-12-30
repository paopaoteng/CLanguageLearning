#ifndef __GETCH_H__
#define __GETCH_H__

#include<stdio.h>

#define MAXBUF 1024

int getch(void);
void ungetch(int c);

#endif

