#include<stdio.h>
#include<pthread.h>
#define MAX 20
pthread_mutex_t the_mutex;
pthread_cond_t condc,condp;
int buffer = 0;

void *producer(void *ptr)
{
	int i;
	for(i = 1;i <= MAX;i++)
	{
		pthread_mutex_lock(&the_mutex);
		while(buffer != 0)
		{
			pthread_cond_wait(&condp, &the_mutex);
		}
		buffer = i;
		printf("生产者线程放入缓冲区数据%d\n", buffer);
		pthread_cond_signal(&condc);
		pthread_mutex_unlock(&the_mutex);
	}
	pthread_exit(0);
}

void *consumer(void *ptr)
{
	int i;
	for(i = 1;i <= MAX;i++)
	{
		pthread_mutex_lock(&the_mutex);
		while(buffer == 0)
		{
			pthread_cond_wait(&condc, &the_mutex);
		}
		printf("消费者线程从缓冲区取出数据%d\n", buffer);
		buffer = 0;
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&the_mutex);
	}
	pthread_exit(0);
}

int main(int argc,char **argv)
{
	pthread_t pro,con;
	printf("条件变量实现生产者消费者学习实例\n");
	pthread_mutex_init(&the_mutex, 0);
	pthread_cond_init(&condc, 0);
	pthread_cond_init(&condp, 0);
	pthread_create(&pro, NULL, consumer, NULL);
	pthread_create(&con, NULL, producer, NULL);
	pthread_join(pro, 0);
	pthread_join(con, 0);
	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&the_mutex);
	return 0;
}
