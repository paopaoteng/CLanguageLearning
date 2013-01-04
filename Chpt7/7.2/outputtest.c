#include<stdio.h>

void outputtest(void)
{
	char *s = "hello, world";

	printf(":%s:\n", s);
	printf(":%10s:\n", s);
	printf(":%.10s:\n", s);
	printf(":%-10s:\n", s);
	printf(":%.15s:\n", s);
    printf(":%-15s:\n", s);
	printf(":%15.10s:", s);
	printf(":%-15.10s:", s);
}

int main(int argc, char *argv[])
{
	outputtest();
	return 0;
}
