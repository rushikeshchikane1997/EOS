//1. Input signal number and a process id from user. Send given signal to the given process using kill() syscall.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include<stdlib.h>

int main()

{   
	pid_t process_id;
	int sig_num;
	printf("enter the sig num : ");
	scanf("%d",&sig_num);

	printf("enter the pid num : ");
	scanf("%d",&process_id);

	if(kill(process_id, sig_num)==0)
	{   
		printf("signal is successfully sent to process\n");
	}
	else
	{   
		perror("Failed to send signal");
		//	exit(0);
	}

	return 0;

}



