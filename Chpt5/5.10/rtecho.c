#include<stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	while(++i < argc)
		printf("%s%s", argv[i], i < argc -1 ? " " : "");
	printf("\n");
	return 0;
}
