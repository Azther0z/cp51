#include <stdio.h>
#include <pthread.h>

void* show_id(void* data) {
	int id;
	id = (int) data;
	printf("This is thread %d\n", id);
}

void main() {
	pthread_t threadArray[10];
	for (int i = 0; i < 10; i++) {
		pthread_create(&threadArray[i], NULL, show_id, i + 1);
	}
	for (int i = 0; i < 10; i++) {
		pthread_join(threadArray[i], NULL);
	}
}