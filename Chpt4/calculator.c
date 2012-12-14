#include<stdio.h>

#define MAX 100

double digit[MAX];
int index = 0;
double pop(void);
void push(double x);
double calc(double a, double b, char c);

int main()
{

	return 0;
}

void push(double x)
{
	if(index == MAX)
	{
		printf("error:the stack is full\n");
		return;
	}
	digit[index++] = x;
}

double pop(void)
{
	if(index == 0)
	{
		printf("error:the stack is empty\n");
		return 0;
	}
	return digit[--index];
}

double calc(double a, double b, char c)
{
	switch(c)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
	return 0;
}

char * getop(char s[], char r[])
{
	int i = 0;
	for(;s[i] == ' ';i++)
	  ;
	while(s[i] != ' ')
	  t[i] = s[i];
	return s + i + 1;
}

double calcres(char s[])
{

}

double rtatof(char s[])
{
	double x = 0;
	double f = 0;
	int sign = 1;
	double n = 1;
	int i = 0;
	
	for(;s[i] == ' ';i++)
	  ;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;

	while(isdigit(s[i]))
		x = x * 10 + s[i++] - '0';

	if(s[i] == '.')
	{
		i++;
		do
		{
			x = x * 10 + (s[i++] - '0');
			n *= 10;
		}while(isdigit(s[i]));

	}


	x = sign * x / n;

	return x;
}

