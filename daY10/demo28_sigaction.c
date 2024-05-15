#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

//step 1: implement signal handler
void sigint_handler(int sig, siginfo_t *si, void *param) {
	printf("SIGINT sent by process %d\n", si->si_pid);
}

int main() {
	int i=1, ret;
	struct sigaction sa;
	// step 2: register signal handler
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = sigint_handler;
	sa.sa_flags = SA_SIGINFO;
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

