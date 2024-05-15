#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// step1: implement SIGINT handler
void sigint_handler(int sig) {
	printf("SIGINT caught: %d || current process: %d\n", sig, getpid());
}

int main() {
	int i=1, ret;
	struct sigaction sa;
	printf("current process id: %d\n", getpid());
	// step2: register signal handler
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
	}
	while(1) {
		printf("running: %d\n", i++);
		sleep(1);
	}
	return 0;
}
