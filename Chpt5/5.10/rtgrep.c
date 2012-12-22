#include<stdio.h>
#include<string.h>
#define MAXLEN 1000

int rt_getline(char *line, int maxlen);

int main(int argc, char *argv[])
{
	char line[MAXLEN];
	int found = 0;
	
	if(argc != 2)
	{
		printf("Usage:find pattern\n");
	}
	else
	{
		while(rt_getline(line, MAXLEN) > 0)
		{
			if(strstr(line, argv[1]) != NULL)
			{
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
}

/*获取一行字符串*/
int rt_getline(char *line, int maxlen)
{
	int c,i;
	
	i = 0;

	while((c = getchar()) != EOF && c != '\n' && i < maxlen - 1)
	{
		line[i] = c;
		i++;
	}

	if(c == '\n')
	{
		line[i++] = '\n';
	}
	
	line[i] = '\0';

	return i;
}
