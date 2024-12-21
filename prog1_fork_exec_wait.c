#include <stdio.h>    // For printf()
#include <stdlib.h>   // For exit()
#include <sys/types.h> // For pid_t
#include <sys/wait.h>  // For wait()
#include <unistd.h>    // For fork()

int main() {
    pid_t pid; 
    pid = fork();  // Create a new process

    if (pid == 0) { // Child process
        printf("It is the child process and pid is %d\n", getpid());
        for (int i = 0; i < 8; i++) {
            printf("%d\n", i);
        }
        exit(0); // Exit the child process
    } 
    else if (pid > 0) { // Parent process
        printf("It is the parent process and pid is %d\n", getpid());
        int status;
        wait(&status);  // Wait for child process to finish
        printf("Child is reaped\n");
    } 
    else {  // Fork failed
        printf("Error in forking..\n"); 
        exit(EXIT_FAILURE);
    }

    return 0;
}