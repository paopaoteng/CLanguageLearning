#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
	char *filename1;
	char *filename2;
	FILE *fp1;
	FILE *fp2;
	char line1[MAXLINE];
	char line2[MAXLINE];

	if(argc < 3)
	{
		fprintf(stderr, "please input two filename to compare\n");
		exit(1);
	}

	filename1 = argv[1];
	filename2 = argv[2];

	if((fp1 = fopen(filename1, "r")) == NULL)
	{
		fprintf(stderr, "can't open file %s\n", filename1);
		exit(2);
	}

	if((fp2 = fopen(filename2, "r")) == NULL)
	{
		fprintf(stderr, "can't open file %s\n", filename2);
		exit(2);
	}

	while(fgets(line1, MAXLINE, fp1) != NULL)
	{
		printf("len = %d : %s", strlen(line1), line1);
	}

	while(fgets(line1, MAXLINE, fp1) != NULL && fgets(line2, MAXLINE, fp2) != NULL)
	{
		if(strcmp(line1, line2) != 0)
		{
			printf("the first different line:\n");
			printf("file %s: %s", filename1, line1);
			printf("file %s: %s", filename2, line2);
			break;
		}
	}
	exit(0);
}
