/* The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
The child process print the result and exit. The parent process wait for completion of the child and then exit.                               
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MQ_KEY 0x1234

typedef struct msg {
    long type;
    int data[2];
} msg_t;

int main() {
    int mqid, ret, s;
    
    // Create message queue
    mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
    if(mqid < 0) {
        perror("msgget() failed");
        _exit(1);
    }

    ret = fork();
    if(ret == 0) {
        // Child: initialize and send the message with two numbers
        msg_t m1;
        m1.type = 1;
        printf("Child: enter two numbers: ");
        scanf("%d %d", &m1.data[0], &m1.data[1]);
        ret = msgsnd(mqid, &m1, sizeof(m1.data), 0);
        if(ret < 0) {
            perror("msgsnd() failed");
            _exit(1);
        }
        printf("Child: numbers sent: %d, %d\n", m1.data[0], m1.data[1]);

        // Receive the sum from the parent
       msg_t m3;
        ret = msgrcv(mqid, &m3, sizeof(m3.data), 2, 0);
        if(ret < 0) {
            perror("msgrcv() failed");
            _exit(1);
        }
        printf("Child: sum received: %d\n", m3.data[0]);
        _exit(0);
    } else {
        // Parent: receive the message with two numbers and calculate the sum
        msg_t m2;
        printf("Parent: waiting for the numbers...\n");
        ret = msgrcv(mqid, &m2, sizeof(m2.data), 1, 0);
        if(ret < 0) {
            perror("msgrcv() failed");
            _exit(1);
        }
        int sum = m2.data[0] + m2.data[1];
        printf("Parent: numbers received: %d, %d\n", m2.data[0], m2.data[1]);
        printf("Parent: calculated sum: %d\n", sum);

        // Send the sum back to the child
        msg_t m4;
        m4.type = 2;
        m4.data[0] = sum;
        ret = msgsnd(mqid, &m4, sizeof(m4.data), 0);
        if(ret < 0) {
            perror("msgsnd() failed");
            _exit(1);
        }

        // Wait for child and clean it up
        wait(&s);

        // Destroy the message queue
        msgctl(mqid, IPC_RMID, NULL);
    }
    return 0;
}




































