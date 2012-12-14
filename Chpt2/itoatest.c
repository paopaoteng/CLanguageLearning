#include<stdio.h>
#include<string.h>

/*反转字符串*/
void reverse(char s[])
{
	int i,l;
	char c;
	for(i = 0,l = strlen(s) - 1;i < l;i++,l--)
	{
		c = s[i];
		s[i] = s[l];
		s[l] = c;
	}
}
/*将数字转换为字符串*/
void rtitoa(int n, char s[])
{
	int sign = 1;
	int i = 0;
	unsigned long nn;
	if(n < 0)
	{
		sign = -1;
		nn = (unsigned long)(-n);  /*此处的转换为了防止负数溢出，如最小的负数求相反数仍是负数，故需转换成unsigned long*/
	}
	else
	{
		nn = (unsigned long)n;
	}

	do
	{
		s[i++] = (nn % 10) + '0';
	}while((nn /= 10) > 0);

	if(sign == -1)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
/*将数字转换为字符，并指定最小宽度*/
void rtitoa2(int n, char s[], int l)
{
	int sign = 1;
	int i = 0;
	unsigned long nn;
	if(n < 0)
	{
		sign = -1;
		nn = (unsigned long)(-n);
	}
	else
	{
		nn = (unsigned long)n;
	}

	do
	{
		s[i++] = (nn % 10) + '0';
	}while((nn /= 10) > 0);

	if(sign == -1)
	{
		s[i++] = '-';
	}
	while(i < l)
	  s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

/*将数字转换为字符串，并以base为进制*/
void rtitob(int n, char s[], int base)
{
	int i = 0;
	int digit = 0;
	unsigned long nn = (unsigned long)n;

	do
	{
		digit = nn %base;
		if( digit <= 9 )
		{
			s[i++] = digit + '0';
		}
		else
		{
			s[i++] = digit - 10 + 'a';
		}
	}while((nn /= base) > 0);

	s[i] = '\0';
	reverse(s);
}
int main()
{
	int x = -1234;
	char s[33] = "";
	rtitoa2(x,s,6);
	printf("%s\n", s);
	return 0;
}
