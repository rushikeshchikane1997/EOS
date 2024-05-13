/*. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurretly for 5 seconds and cleaned up properly upon termination.v */
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int ret1,ret2,ret3,count,s1,s2,s3;
	ret1 = fork();
	if(ret1 == 0)
	{
		ret2=fork();
		if(ret2==0)
		{
			ret3=fork();
			if(ret3==0);
			{
	 			for(count = 1; count<6; count++)
				{
					printf("count_A= %d \n",count);		 
					sleep(1);
				}
				_exit(0);	
			}
			for(count = 1; count<6; count++)
			{
      			printf("count_B= %d \n",count);
      			sleep(1);
			}
			waitpid(ret3,&s3,0);
			printf("pid =%d \n",waitpid);
			_exit(0);
		}
		for(count = 1; count<6; count++)
		{
    		printf("count_C= %d \n",count);
    		sleep(1);
		}
   		waitpid(ret2,&s2,0);
	printf("pid =%d \n",waitpid);
  		_exit(0);
	}
	for(count = 1; count<6; count++)
	{
		printf("count_D= %d \n",count);
		sleep(1);
	}
	printf("pid =%d \n",getpid);

	waitpid(ret1,&s1,0);
	printf("pid =%d \n",getpid);
	_exit(0);
  	return 0;
}     












	




















































