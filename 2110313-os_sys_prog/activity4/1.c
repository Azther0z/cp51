#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("Please enter UNIX command");
		return (0);
	}
	pid_t pid;
	pid = fork() ;
	if (pid < 0) {
		printf("Error : cannot fork\n");
		exit(1);
	} else if (pid == 0) {
		char* arg[argc];
		for (int i = 1; i < argc; i++) {
			arg[i - 1] = argv[i];
		}
		arg[argc - 1] = (char*)0;
		if (execvp(argv[1], arg) == -1) {
			printf("Command error");
		}
	} else {
		wait(NULL);
		return (0);
	}
}