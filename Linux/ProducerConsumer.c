#include <stdio.h>
#include <pthread.h>

#define MAX 100     /*需要生产的数量*/

pthread_mutex_t g_mutex;    /*互斥锁*/
pthread_cond_t g_cond_p, g_cond_c;    /*条件变量*/
int g_buffer = 0;    /*缓冲区*/

void *Producer(void *ptr)
{
	int i;
	for (i = 1; i <= MAX; ++i)
	{
		pthread_mutex_lock(&g_mutex);
		while (g_buffer != 0)
			pthread_cond_wait(&g_cond_p, &g_mutex);
		g_buffer = i;
		printf("the producer %d\n", i);
		pthread_cond_signal(&g_cond_c);
		pthread_mutex_unlock(&g_mutex);
	}
	pthread_exit(0);
}

void *Consumer(void *ptr)
{
	int i;
	for (i = 1; i <= MAX; ++i)
	{
		pthread_mutex_lock(&g_mutex);
		while (g_buffer == 0)
			pthread_cond_wait(&g_cond_c, &g_mutex);
		g_buffer = 0;
		printf("the consumer %d\n", i);
		pthread_cond_signal(&g_cond_p);
		pthread_mutex_unlock(&g_mutex);
	}
	pthread_exit(0);
}

int main()
{
	pthread_t pro, con;
	//初始化
	pthread_mutex_init(&g_mutex, 0);
	pthread_cond_init(&g_cond_p, 0);
	pthread_cond_init(&g_cond_c, 0);
	//创建线程
	pthread_create(&pro, 0, Producer, 0);  //生产者
	pthread_create(&con, 0, Consumer, 0);  //消费者
	//等待线程结束
	pthread_join(pro, 0);
	pthread_join(con, 0);
	//销毁条件变量和互斥量
	pthread_cond_destroy(&g_cond_p);
	pthread_cond_destroy(&g_cond_c);
	pthread_mutex_destroy(&g_mutex);
	return 0;
}