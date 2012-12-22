/*C程序设计语言 第五章 第十节 练习5-13
 *编写程序tail，将起输入中的最后n行打印出来。默认情况下，n的值为10
 *但可以通过一个可选参数改变n的值
 *如：tail -n */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINES 4
#define MAXLEN 100
#define MAX(a, b) (a) > (b) ? (a) : (b)

int readlines(char *lines[]);
int rt_getline(char *line, int maxlen);

int main(int argc, char *argv[])
{
	char *lines[MAXLEN];
	int nlines = 0;
	int last = 10;
	int i = 0;
	char *p;
	
	if(argc > 1)
	{
		p = argv[1];
		if(p[0] == '-' && isdigit(p[1]))
		{
			last = atoi(p + 1);
		}
	}

	if((nlines = readlines(lines)) > 0)
	{
		if(last > MAXLINES)
		{
			printf("error:the input n is too large\n");
			exit(-1);
		}
		for(i = MAX(nlines - last, 0);i < nlines;i++)
		{
			printf("line %d: %s\n", i + 1, lines[i % MAXLINES]);
		}
	}

	return 0;
}

int readlines(char *lines[])
{
	char str[MAXLEN];
	char *p;
	int nlines = 0;
	int len = 0;

	while((len = rt_getline(str, MAXLEN)) > 0)
	{
		if((p = (char*)malloc(len)) != NULL)
		{
			str[len - 1] = '\0';
			strcpy(p, str);
			lines[nlines++ % MAXLINES] = p;
		}
		else
		{
			printf("error:malloc fail\n");
			exit(-1);
		}
	}
	return nlines;
}

/*获取一行字符串*/
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
