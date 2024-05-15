#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
	// sa.sa_mask will be set in PCB i.e. all signals masked
	int i;
	for(i=1; i<=5; i++) {
		printf("signal caught: %d\n", sig);
		sleep(1);
	}
	// restore old sig mask i.e. all signals unmasked
}

int main() {
	int i=1, ret;
	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	sigfillset(&sa.sa_mask); // mask to set to all 1's i.e. all sig masked
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
	}
	while(1) {
		printf("running: %d\n", i++);
		sleep(2);
	}
	return 0;
}

