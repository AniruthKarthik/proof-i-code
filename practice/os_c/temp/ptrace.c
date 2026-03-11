#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  printf("=== PTRACE DEMO ===\n");

  pid_t pid = fork();

  if (pid == 0) {

    printf("Child process started\n");
    printf("PID: %d\n", getpid());

    ptrace(PTRACE_TRACEME, 0, NULL, NULL);

    printf("Child executing program\n");

    execl("/bin/ls", "ls", NULL);

  } else {

    printf("Parent tracing child process\n");
    printf("Child PID: %d\n\n", pid);

    wait(NULL);

    printf("Child stopped. Debugging events captured\n");

    ptrace(PTRACE_CONT, pid, NULL, NULL);

    wait(NULL);

    printf("Child execution finished\n");
  }

  return 0;
}
