#include <stdio.h>
#include <pthread.h>

void *ThreadSummation(void *args);
int g_sum = 0;
pthread_mutex_t mutex;

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int range1[] = {1, 50000000};
	int range2[] = {50000000, 1};

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&t1, NULL, ThreadSummation, (void *)range1);
	pthread_create(&t2, NULL, ThreadSummation, (void *)range2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("result: %d\n", g_sum);
	pthread_mutex_destroy(&mutex);
	return 0;
}

void *ThreadSummation(void *arg)
{
	int start = ((int*)arg)[0];
	int end = ((int*)arg)[1];

	pthread_mutex_lock(&mutex);
	if (start < end)
		while (start <= end)
		{
			g_sum += start;
			start++;
		}
	else
	{
		while (start >= end)
		{
			g_sum -= start;
			start--;
		}
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}
