#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // Include header file for wait function

int value = 5;

int main() {
    pid_t pid; // Corrected data type of pid_t
    pid = fork();
    
    if (pid == 0) { // Child process
        value += 15;
        printf("CHILD: value = %d\n", value); // Output from child process
        return 0;
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("PARENT: value = %d\n", value); // Output from parent process
        return 0;
    }
}
