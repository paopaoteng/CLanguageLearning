#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindexr(char source[], char searchfor[]);

char pattern[] = "ould";

main()
{
	char line[MAXLINE];
	while(mygetline(line, MAXLINE) > 0)
	{
		/*
		if(strindex(line, pattern) >= 0)
		{
			printf("%s", line);
		}*/

		printf("%d\n", strindexr(line, pattern));
	}

	return 0;
}

/*getline 函数 将行保存到s中，并返回行的长度*/
int mygetline(char s[], int lim)
{
	int c,i;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
	  s[i++] = c;
	if(c == '\n')
	  s[i++] = c;
	s[i] = '\0';
	return i;
}

/*strindex 函数：返回t在s中的位置，若未找到则返回-1*/
int strindex(char s[], char t[])
{
	int i,j,k;
	for(i = 0;s[i] != '\0';i++)
	{
		for(j = 0;t[j] != '\0';j++)
		{
			if(s[i + j] != t[j])
			  break;
		}
		if(j > 0 && t[j] == '\0')
		  return i;
	}
	return -1;
}

/*返回t在s中最右边的位置，若不存在，则返回-1*/
int strindexr(char s[], char t[])
{
	int i,j,ls,lt;
	ls = strlen(s);
	lt = strlen(t);
	if(ls == 0 || lt == 0)
	  return -1;

	for(i = ls - lt - 1;i >= 0;i--)
	{
		for(j = 0;j < lt;j++)
		{
			if(s[i + j] != t[j])
			  break;
		}
		if(j == lt)
			return i;
	}
	if(i < 0)
	  return -1;
}
