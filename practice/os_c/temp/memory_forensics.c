#include <stdio.h>
#include <stdlib.h>

void execute(const char *cmd) {

  char buffer[1024];
  FILE *fp;

  printf("\nCommand: %s\n", cmd);

  fp = popen(cmd, "r");

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }

  pclose(fp);
}

int main() {

  printf("\n=== MEMORY FORENSICS DEMO ===\n");

  execute("insmod lime-$(uname -r).ko \"path=/tmp/memdump.lime format=lime\"");

  execute("volatility -f memdump.lime --profile=LinuxKali pslist");

  execute("volatility -f memdump.lime --profile=LinuxKali linux_malfind");

  printf("\nMemory analysis complete\n");

  return 0;
}
