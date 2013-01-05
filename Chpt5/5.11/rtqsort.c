#include<stdio.h>
#include<string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void rt_qsort(void *lineptr, int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines = 0;        /* 读入的输入行数 */
	int numeric = 0;       /* 若进行数值排序，则numeric值为1 */

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		dnumeric = 1;
	
	if((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		rt_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric == 1 ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}


