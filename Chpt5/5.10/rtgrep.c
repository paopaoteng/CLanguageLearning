#include<stdio.h>
#include<string.h>
#define MAXLEN 1000

int rt_getline(char *line, int maxlen);

int main(int argc, char *argv[])
{
	char line[MAXLEN];
	int found = 0;
	long lineno = 0;
	int except = 0;
	int number = 0;
	char c;
	char *p;
	int i = 1;
	int j = 1;
	
	/*p指向外部调用输入的参数*/
	while(--argc > 0 && (p = argv[i++], p[0] == '-'))
	{
		/*c为p的第j个字符*/
		while(c = p[j++])
		{
			switch(c)
			{
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
	}

	if(argc != 1)
	{
		printf("Usage: find -x -n pattern\n");
	}
	else
	{
		while(rt_getline(line, MAXLEN) > 0)
		{
			lineno++;
			/*except为0，显示包含，为1，显示不包含*/
			if((strstr(line, p) != NULL) != except)
			{
				if(number)
				{
					printf("%ld:", lineno);
				}
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
