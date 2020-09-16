#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int top = 0;		
int buf[100];		

pthread_mutex_t mutex;
pthread_cond_t cond;

// Produce function: increase top by 1
void *producer_func(void *tid) {
	while (1) {
		pthread_mutex_lock(&mutex);
		while (top >= 100)
			pthread_cond_wait(&cond, &mutex);
		buf[top] = rand()%100;
		printf("Produce: %d\n", buf[top]);
		top++;
		sleep(1); 	
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

// Consumer function: decrease top by 1
void *consumer_func(void *tid) {
	while(1) {
		pthread_mutex_lock(&mutex);
		while (top <= 0)
			pthread_cond_wait(&cond, &mutex);
		--top;
		printf("Consume: %d\n", buf[top]);
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}


int main() {
	pthread_t consumer, producer;
	pthread_attr_t attr;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_create(&consumer, &attr, consumer_func, (void *)&consumer);
	pthread_create(&producer, &attr, producer_func, (void *)&producer);

	pthread_join(consumer, NULL);
	pthread_join(producer, NULL);

	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	pthread_exit(NULL);

	return EXIT_SUCCESS;
}
