#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* threadid)
{
	long tid = (long)threadid;
	printf("Thread's ID - #%ld\n", tid);
	pthread_exit(NULL);
}

int main()
{
	int n;
	scanf("%d", &n);
	pthread_t threads[n];

	for (int i = 0; i < n; i++)
	{
		pthread_create(threads + i, NULL, thread_func, (void*)i);
		pthread_join(threads[i], NULL);
	}

	pthread_exit(NULL);
	return 0;
}