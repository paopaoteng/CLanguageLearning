#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main(int argc, char *argv[])
{
	while(gettoken() != EOF)
	{
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if(tokentype != '\n')
		{
			printf("syntax error\n");
		}
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken()
{
	int c, getch
}
