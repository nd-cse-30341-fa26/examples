/* hello-n.c */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
	pid_t pid = fork();
	if (pid == 0) { // Child
	    printf("[%d] Hello from child %d\n", getpid(), i);
	    exit(EXIT_SUCCESS);
	}
    }
    return EXIT_SUCCESS;
}
