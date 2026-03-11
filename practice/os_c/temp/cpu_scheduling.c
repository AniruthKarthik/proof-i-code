#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {

  printf("=== CPU PRIORITY DEMO ===\n");

  int priority = getpriority(PRIO_PROCESS, 0);
  printf("Initial nice value: %d\n", priority);

  printf("\nSetting nice value to +10 (lower priority)\n");

  nice(10);

  priority = getpriority(PRIO_PROCESS, 0);
  printf("Updated nice value: %d\n\n", priority);

  printf("Running heavy loop to observe scheduling behavior\n");

  for (long i = 0; i < 1000000000; i++) {
    if (i % 200000000 == 0)
      printf("Loop progress: %ld\n", i);
  }

  printf("Program completed\n");

  return 0;
}
