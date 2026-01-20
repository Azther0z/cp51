#include <stdio.h>
#include <unistd.h>

int main() {
	printf("I am the parent process. My PID is %d\n", getpid());
	int pid = fork();
	if (pid == 0) {
		printf("I am the child process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
		int pid2 = fork();
		if (pid2 == 0) {
			printf("I am the grandchild process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
		}
	}
}