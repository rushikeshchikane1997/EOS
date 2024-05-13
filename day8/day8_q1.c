#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
  
int main() {
	int ret, i, s;
	ret = fork();
	if(ret == 0) {
		// child process
		for(i=1; i<=5; i++) {
			printf("count: %d\n", i);
			sleep(5);
		}
		_exit(0);
	}
	else {
		// parent process
		for(i=1; i<=5; i++) {
			printf("parent: %d\n", i);
			sleep(5);
			if(i == 5) {
				wait(&s);
				printf("child exit: %d\n", WEXITSTATUS(s));
			}
		}
	}
	return 0;
}



































