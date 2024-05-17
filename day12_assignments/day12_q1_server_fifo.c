// server.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int num1, num2, sum;
    int fd1, fd2;

    // Open the FIFOs
    fd1 = open("client", O_RDONLY);
    if (fd1 == -1) {
        perror("open client failed");
        exit(1);
    }

    fd2 = open("server", O_WRONLY);
    if (fd2 == -1) {
        perror("open server failed");
        close(fd1);
        exit(1);
    }

    // Read two number from client
    read(fd1, &num1, sizeof(int));
    read(fd1, &num2, sizeof(int));

    // Calculate the sum
    sum = num1 + num2;

    // Send the sum  to the client
    write(fd2, &sum, sizeof(int));

    
    close(fd1);
    close(fd2);

    return 0;
}











































