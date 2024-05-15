#include <stdio.h>
#include <unistd.h>

int main() {
	printf("started! ");
	fork();
	printf("completed!\n");
	return 0;
}

