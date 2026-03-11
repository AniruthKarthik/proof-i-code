#include <stdio.h>
#include <stdlib.h>

void run_command(const char *cmd) {

  char buffer[1024];
  FILE *fp;

  printf("\n-------------------------------------\n");
  printf("Executing: %s\n", cmd);
  printf("-------------------------------------\n");

  fp = popen(cmd, "r");

  if (fp == NULL) {
    printf("Command failed\n");
    return;
  }

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }

  pclose(fp);

  printf("\nExecution finished\n");
}

int main() {

  printf("\n=== PENETRATION TESTING DEMO ===\n");

  printf("\n1. Host Discovery Scan\n");

  run_command("nmap -sn -O 192.168.1.0/24");

  printf("\n2. Port Discovery Scan\n");

  run_command("nmap -p- 192.168.1.10");

  printf("\n3. Vulnerability Scan\n");

  run_command("nmap --script vuln 192.168.1.10");

  printf("\nAll scans completed\n");

  return 0;
}
