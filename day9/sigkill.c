
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int signal_number;
    pid_t process_id;

    // Input signal number from user
    printf("Enter signal number: ");
    scanf("%d", &signal_number);

    // Input process ID from user
    printf("Enter process ID: ");
    scanf("%d", &process_id);

    // Send the signal to the specified process
    if (kill(process_id, signal_number) == 0) {
        printf("Signal %d successfully sent to process %d\n", signal_number, process_id);
    } else {
        perror("Failed to send signal");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

