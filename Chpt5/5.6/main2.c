#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES 5000            /* 进行排序的最大文本行数*/
#define MAXLEN 1000          /*每个输入文本行的最大长度*/

char *lineptr[MAXLINES];         /*指向文本行的指针数组*/

int readlines(char lineprt[][MAXLEN], int nlines);
void writelines(char lineptr[][MAXLEN], int nlines);

void rt_qsort(char *lineptr[], int left, int right);

int main()
{
	int nlines,i;
	char str[MAXLINES][MAXLEN];
	
	if((nlines = readlines(str, MAXLINES)) >= 0)
	{
		for(i = 0;i < nlines;i++)
		{
			lineptr[i] = str[i];
		}
		rt_qsort(lineptr, 0, nlines - 1);
		writelines(str, nlines);
		return 0;
	}
	else
	{
		printf("error:input too big to sort\n");
		return 1;
	}
}

int rt_getline(char *, int);
char *alloc(int len);
void rt_swap(char *v[], int i, int j);


/*readlines函数：读取输入行*/
int readlines(char lineptr[][MAXLEN], int maxlines)
{
	int len, nlines;

	nlines = 0;
	while((len = rt_getline(lineptr[nlines], MAXLEN)) > 0)
	{
		if(nlines >= maxlines)
		{
			return -1;
		}
		nlines++;
	}
	return nlines;
}

void writelines(char lineptr[][MAXLEN], int nlines)
{
	while(nlines--)
	{
		printf("%s\n", *lineptr++);
	}
}

int rt_getline(char *line, int maxlen)
{
	int c,i;

	for(i = 0;i < maxlen && (c = getchar()) != EOF && c != '\n';++i)
	{
		line[i] = c;
	}

	if(c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

void rt_qsort(char *v[], int left, int right)
{
	int i, last;

	if(left >= right)
	{
		return;
	}

	rt_swap(v, left, (left + right) / 2);
	last = left;
	for(i = left;i <= right;i++)
	{
		if(strcmp(v[i], v[left]) < 0)
		{
			rt_swap(v, ++last, i);
		}
	}
	rt_swap(v, left, last);
	rt_qsort(v, left, last -1);
	rt_qsort(v, last + 1, right);
}

void rt_swap(char *v[], int i, int j)
{
	char *p;
	p = v[i];
	v[i] = v[j];
	v[j] = p;
}

char *alloc(int len)
{
	return (char*)malloc(len);
}

