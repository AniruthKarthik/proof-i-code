#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

void print_header(const char *title) {
    printf("\n========================================\n");
    printf("  %s\n", title);
    printf("========================================\n");
}

void signal_handler(int sig) {
    printf("[Signal] Caught signal %d (SIGUSR1). Handling gracefully...\n", sig);
}

void handle_child_process() {
    printf("[Child]  PID: %d, Parent PID: %d\n", getpid(), getppid());
    
    // Demonstrate process priority
    printf("[Child]  Current Priority (Nice): %d\n", nice(0));
    nice(10);
    printf("[Child]  New Priority (Nice) after nice(10): %d\n", nice(0));

    printf("[Child]  Executing 'ps -f' to show process status...\n");
    char *args[] = {"ps", "-f", NULL};
    if (execvp(args[0], args) == -1) {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
}

void handle_parent_process(pid_t child_pid) {
    int status;
    printf("[Parent] PID: %d, waiting for Child (PID: %d)...\n", getpid(), child_pid);
    
    // Send a signal to itself to demonstrate signal handling
    printf("[Parent] Sending SIGUSR1 to myself...\n");
    raise(SIGUSR1);

    pid_t waited_pid = wait(&status);
    
    if (waited_pid == -1) {
        perror("wait failed");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status)) {
        printf("[Parent] Child %d exited normally with status %d\n", waited_pid, WEXITSTATUS(status));
    }

    // Show one environment variable
    printf("[Parent] PATH environment variable: %s\n", getenv("PATH"));
}

int main() {
    print_header("PROCESS MANAGEMENT DEMONSTRATION");

    // Register signal handler
    signal(SIGUSR1, signal_handler);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        handle_child_process();
    } else {
        handle_parent_process(pid);
    }

    printf("\n[System] Process Management Demo Completed.\n");
    return EXIT_SUCCESS;
}
