#include <stdio.h>
#include <unistd.h>


int main() {
    int pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        wait(200);
        printf("Child process finished\n");
    }

    return 0;
}