#include<stdio.h>

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

int main()
{
	printf("%d\n",rtatoi("123"));
	printf("%d\n",rtatoi("   -12312"));
    printf("%d\n",rtatoi("+456"));	
	rtatoi("12");
	r
	return 0;
}
