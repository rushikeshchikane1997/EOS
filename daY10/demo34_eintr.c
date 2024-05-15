#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
	printf("SIGINT handled.\n");
}

int main() {
	char str[32];
	int ret;
	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
	}

	printf("enter a string: \n");
	ret = read(STDIN_FILENO, str, sizeof(str));
	// STDIN_FILENO = 0 (declared in header file)
	if(ret == -1)
		perror("read() failed");
	printf("read() returned: %d\n", ret);
	return 0;
}


