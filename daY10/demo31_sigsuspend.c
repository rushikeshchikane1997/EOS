#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
	printf("signal caught: %d\n", sig);
}

int main() {
	sigset_t set;
	int i=1, ret;
	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
	}

	printf("Waiting for SIGINT or SIGTERM!\n");
	sigfillset(&set);			// 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111 
	sigdelset(&set, SIGTERM);	// 11111111 11111111 11111111 11111111 11111111 11111111 10111111 11111111
	sigdelset(&set, SIGINT);	// 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111101
	sigsuspend(&set);
		//1. set sigmask field to given signal set.
		//2. block current process for any of the enabled (unmasked) signal.
		//3. when unmasked signal received, wakeup the process and restore old sigmask field
		//by default, pending but unmasked signal's handler will be executed. 
	if(ret < 0) {
		perror("sigprocmask() failed");
		_exit(1);
	}
	while(1) {
		printf("running: %d\n", i++);
		sleep(2);
	}
	return 0;
}

