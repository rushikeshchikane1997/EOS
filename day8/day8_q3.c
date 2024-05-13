#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
int ret,s,i,j;
i=1;
while(1){
ret=fork();
if(ret==0)
{
 printf("child");
_exit(0);
}

else if (ret==-1)
{
printf("failed fork");
break;
}

else 
{
i++;
printf("count = %d \n",i);
}
}
for(j=1 ; j<=i ; j++)
wait(&s);

return 0;
}

































