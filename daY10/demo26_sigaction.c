#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/*

struct sigaction sa_new, sa_old;
memset(&sa_new, 0, sizeof(struct sdigaction));
sa_new.sa_handler = sig_handler;
struct sigaction sa_new, sa_old;
ret=sigaction(signum,&sa_new,NULL);
memset(&sa_new, 0, sizeof(struct sigaction));
sa_new.sa_handler = sig_handler;
ret = sigaction(signum, &sa_new, &sa_old); 
*/

// step1: implement SIGINT handler
void sigint_handler(int sig) {
	printf("SIGINT caught: %d\n", sig);
}

int main() {
	int i=1, ret;
	struct sigaction sa;
	// step2: register signal handler
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret == -1) {
		perror("sigaction() failed");
		_exit(1);
	}
	while(1) {
		printf("running: %d\n", i++);
		sleep(1);
	}
	return 0;
}
