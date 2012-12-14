#include<stdio.h>
#include<math.h>

int rtatoi(char s[])
{
	int n = 0;
	int i = 0;
	int sign = 1;
	while(isspace(s[i]))
	  i++;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
	  i++;
	for(n = 0;isdigit(s[i]);i++)
	  n = 10 * n + s[i] - '0';
	return sign * n;
}

/*练习4-2 将atof扩展成支持科学计数法表示*/
double rtatof(char s[])
{
	double x = 0;
	double f = 0;
	int sign = 1;
	double n = 1;
	int i = 0;
	double e = 1;
	
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

	if(s[i] == 'e' || s[i] == 'E')
	{
		i++;
		e = pow(10, rtatoi(s + i));
	}

	x = sign * x / n * e;

	return x;
}

int main()
{
	char s[20] = "123.456";
	scanf("%s",s);
	printf("%lf\n", rtatof(s));
	return 0;
}
