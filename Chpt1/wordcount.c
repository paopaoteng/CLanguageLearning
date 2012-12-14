#include<stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c,state;

	state = OUT;

	while((c = getchar()) != EOF)
	{
		if((c == ' ' || c == '\t' || c == '\n') && state == IN)
		{
			printf("\n");
		}
		else
		{
			printf("%c", c);
			state = IN;
		}
	}
}
