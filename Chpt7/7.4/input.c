#include<stdio.h>
#include<stdarg.h>

void minscanf(char *fmt, ...)
{
	char *p;
	va_list ap;
	int *pival;
	float *pdval;
	float a;
	char *s;


	va_start(ap, fmt);
	for(p = fmt;*p;p++)
	{
		if(*p == '%')
		{
			switch(*++p)
			{
				case 'd':
					pival = va_arg(ap, int*);
					scanf("%d", pival);
					break;
				case 'f':
					pdval = va_arg(ap, float*);
					scanf("%f", pdval);
					break;
				case 's':
					s = va_arg(ap, char*);
					scanf("%s", s);
					break;
				default:
					break;
			}
		}
	}
	va_end(ap);
}

int main(int argc, char *argv[])
{
	int a;
	float b;
	char s[20];

	minscanf("%d%f%s", &a, &b, s);
	printf("a = %d b = %f s = %s\n", a, b, s);
	return 0;
}
