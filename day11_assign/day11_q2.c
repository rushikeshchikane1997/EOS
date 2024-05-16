#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    int ret;

    // Create the first pipe
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        return 1;
    }

    // Create the second pipe
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        return 1;
    }

    // Fork the process
    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }

    if (ret == 0) { // Child process
        // Close unused pipe ends
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        // Accept two numbers from the user
        int num1, num2;
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);

        // Send the numbers to the parent
        write(pipe1[1], &num1, sizeof(int));
        write(pipe1[1], &num2, sizeof(int));
        close(pipe1[1]); // Close write end of pipe1

        // Receiveing  the sum from the parent
        int sum;
        read(pipe2[0], &sum, sizeof(int));
        close(pipe2[0]); // Close read end of pipe2

        // Print the result
        printf("Child received sum: %d\n", sum);

    } else { // Parent process
        // Close unused pipe ends
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        // Receive the numbers from the child
        int num1, num2;
        read(pipe1[0], &num1, sizeof(int));
        read(pipe1[0], &num2, sizeof(int));
        close(pipe1[0]); // Close read end of pipe1

        // Calculate the sum 
        int sum = num1 + num2;

        // Send the sum to the child
        write(pipe2[1], &sum, sizeof(int));
        close(pipe2[1]); // Close write end of pipe2

        // Wait for the child process to complete
        wait(NULL);

        // Parent process exits
        printf("Parent completed!\n");
    }

    return 0;
}






















































