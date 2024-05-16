#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd;
    pid_t pid;

    printf("parent started!\n");

    // Fork the process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Child process
        // Open the input file
        fd = open("in.txt", O_RDONLY);
        if (fd < 0) {
            perror("open");
            return 1;
        }

        // Redirect standard input to the file
        if (dup2(fd, STDIN_FILENO) < 0) {
            perror("dup2");
            close(fd);
            return 1;
        }
        close(fd); // Close the original file descriptor

        // Execute the "wc" command
        execlp("wc", "wc", NULL);

        // If execlp fails
        perror("execlp");
        return 1;
    } else { // Parent process
        wait(NULL); // Wait for the child process to complete
    }

    printf("parent completed!\n");
    return 0;
}

