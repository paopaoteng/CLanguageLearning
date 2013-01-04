#include<stdio.h>
#include<string.h>

#define MAXLEN 100

char rt_tolower(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

char rt_tohiher(char c)
{
	return (c >= 'a' && c <= 'z') ? c + 'A' - 'a' : c;
}


int main(int argc, char *argv[])
{
	char s[MAXLEN];
	char (*p)(char);
	int i = 0;

	if(argc == 1)
		return 0;

	printf("argv[0] = %s\n", argv[0]);

	if(strcmp(argv[0], "tolower") == 0)
		p = rt_tolower;
	else
		p = rt_tohiher;

	while(*argv[1])
	{
		s[i++] = (*p)(*argv[1]);
		argv[1]++;
	}
	s[i] = '\0';

	printf("%s\n", s);
	return 0;
}
