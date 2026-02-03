#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* threadShow(void* data) {
	char* str;
	str = (char*) data;
	printf("%s\n", str);
}

void main() {
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("Error: cannot fork\n");
		exit(1);
	} else if (pid == 0) {
		pthread_t first, second;
		pthread_create(&first, NULL, threadShow, "First thread from child process");
		pthread_create(&second, NULL, threadShow, "Second thread from child process");
		pthread_join(first, NULL);
		pthread_join(second, NULL);
	} else {
		pthread_t first, second;
		pthread_create(&first, NULL, threadShow, "First thread from parent process");
		pthread_create(&second, NULL, threadShow, "Second thread from parent process");
		pthread_join(first, NULL);
		pthread_join(second, NULL);

	}
}