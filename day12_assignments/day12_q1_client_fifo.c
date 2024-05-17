// client.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int num1, num2, sum;
	int fd1, fd2;

	// Open the FIFOs
	fd1 = open("client", O_WRONLY);
	if (fd1 == -1) {
		perror("open client failed");
		exit(1);
	}

	fd2 = open("server", O_RDONLY);
	if (fd2 == -1) {
		perror("open server failed");
		close(fd1);
		exit(1);
	}

	// accept the nums from user
	printf("Enter two nums: ");
	scanf("%d %d", &num1, &num2);

	// Send the nums to the server
	write(fd1, &num1, sizeof(int));
	write(fd1, &num2, sizeof(int));

	// sum reading from the server
	read(fd2, &sum, sizeof(int));


	printf("The sum is: %d\n", sum);


	close(fd1);
	close(fd2);

	return 0;
}











































