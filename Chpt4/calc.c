#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char s[]);
void push(double x);
double pop(void);
int getch(void);
void ungetch(int);

int main()
{
	int type;
	double op2,op1;
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
				  printf("error:zero divisor\n");
				break;
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error:unknown command %s\n", s);
				break;

		}
	}
	return 0;
}

void push(double f)
{
	/*printf("f = %lf\n", f);*/
	if(sp < MAXVAL)
	  val[sp++] = f;
	else
	  printf("error:the stack is full\n");
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error:the stack is empty\n");
		return 0;
	}
}

int getop(char s[])
{
	int c, i;

	while((s[0] = c = getch()) == ' ' || c == '\t')
	  ;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
	{
		int c2;
		/*若为换行符或者非正负号，则直接返回符号*/
     	/*	printf("c = %c\n",c);*/
		if( c == '\n' || !(c == '-' || c == '+'))
		{
			return c;
		}
		/*获取下一个字符，判断是否为数字，以支持正负号的输入*/
		c2 = getch();
		ungetch(c2);
		/*printf("c2 = %c\n", c2);*/
		if(!isdigit(c2))
		{
			return c;
		}
	}

	i = 0;

	if(isdigit(c) || c == '-')
	{
		while((s[++i] = c = getch()) && isdigit(c))
		  ;
	}
	if(c == '.')
	{
		while((s[++i] = c = getch()) && isdigit(c))
		  ;
	}
	s[i] = '\0';
	/*printf("s = %s\n", s);*/
	if(c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp < BUFSIZE)
	{
		buf[bufp++] = c;
	}
	else
	{
		printf("error:the buf is full\n");
	}
}
