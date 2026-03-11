#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  printf("=== PROCESS CREATION DEMO ===\n");
  printf("Parent process started\n");
  printf("Parent PID: %d\n\n", getpid());

  pid_t pid = fork();

  if (pid < 0) {
    printf("Fork failed\n");
    return 1;
  }

  if (pid == 0) {
    printf("---- CHILD PROCESS ----\n");
    printf("Child PID: %d\n", getpid());
    printf("Parent PID seen by child: %d\n", getppid());

    printf("\nChild will now execute 'ls -l'\n");
    printf("Current process image will be replaced using exec()\n\n");

    execlp("ls", "ls", "-l", NULL);

    printf("This line never runs if exec succeeds\n");
  } else {
    printf("---- PARENT PROCESS ----\n");
    printf("Parent PID: %d\n", getpid());
    printf("Child PID created: %d\n", pid);

    printf("\nParent waiting for child to finish...\n");

    wait(NULL);

    printf("\nChild finished execution\n");
    printf("Parent exiting\n");
  }

  return 0;
}
