#include<stdio.h>
#include<pthread.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *ptr)
{
	printf("Hello World!Greetings from thread %d\n", *(int*)ptr);
	return 0;
}

int main(int argc,char **argv)
{
	pthread_t threads[NUMBER_OF_THREADS];
	int i,res;
	
	for(i = 0;i < NUMBER_OF_THREADS;i++)
	{
		pthread_create(&threads[i], NULL, print_hello_world, &i);
	//	pthread_join(threads[i], NULL);
	}
	pthread_join(threads[9], NULL);
	getchar();

	return 0;
}
