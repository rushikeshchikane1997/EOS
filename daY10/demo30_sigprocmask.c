#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
/*
int main() {
	sigset_t set;
	int i=1, ret;
	sigemptyset(&set);			// 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 
	sigaddset(&set, SIGTERM);	// 00000000 00000000 00000000 00000000 00000000 00000000 01000000 00000000 
	sigaddset(&set, SIGINT);	// 00000000 00000000 00000000 00000000 00000000 00000000 01000000 00000010
	ret = sigprocmask(SIG_SETMASK, &set, NULL); // set sig mask field in current process PCB
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
*/

int main ()
{
sigset_t set ;
int i=1, ret ;
sigemptyset(&set);
sigaddset(&set, SIGINT);
sigaddset(&set, SIGTERM);
ret = sigprocmask(SIG_SETMASK,&set,NULL);

while(1)
{
printf("running: %d\n", i++);
          sleep(2);
      }
      return 0;
  }









