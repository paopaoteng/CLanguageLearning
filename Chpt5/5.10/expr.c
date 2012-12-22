/*C程序设计语言 第五章 第十节 练习5-10
 *使用命令行计算逆波兰表达式的值
 *例如expr 2 3 4 + *
 *输出:result is 14
 *注意:输入乘号“*”时，需要使用引号将*引起来，否则linux将*识别为该目录下所有的文件明
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 1000

static int number[MAXLEN];
static int pos = 0;

int pop(void);
void push(int n);

int main(int argc, char *argv[])
{
	char opt;
	int a,b;
	char *p;

	while(p = *(++argv))
	{
		printf("p = %s\n", p);
		if(isdigit(p[0]))
		{
			push(atoi(p));
		}
		else
		{
			switch(p[0])
			{
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					a = pop();
					push(pop() - a);
					break;
				case '/':
					a = pop();
					push(pop() / a);
					break;
				default:
					printf("error:unknown input\n");
					exit(-1);
			}
		}
	}
	printf("result = %d\n", pop());

	return 0;
}



int pop(void)
{
	if(pos <= 0)
	{
		printf("error:the stack is empty\n");
		exit(-1);
	}
	return number[--pos];
}

void push(int n)
{
	if(pos >= MAXLEN)
	{
		printf("error: the stack is full\n");
		exit(-1);
	}
	number[pos++] = n;
}
