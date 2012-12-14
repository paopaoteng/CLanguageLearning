#include<stdio.h>

main()
{
	int c,n;
	n = 0;
	while((c = getchar()) != EOF)
	{
		++n;
	}
	printf("%d\n",n);
}
