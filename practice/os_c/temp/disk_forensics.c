#include <stdio.h>
#include <stdlib.h>

void run(const char *cmd) {

  char buffer[1024];
  FILE *fp;

  printf("\nRunning: %s\n", cmd);

  fp = popen(cmd, "r");

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }

  pclose(fp);
}

int main() {

  printf("\n=== DIGITAL FORENSICS DEMO ===\n");

  run("dcfldd if=/dev/sdb of=disk.img hash=sha256");

  run("sha256sum disk.img");

  run("mount -o ro,loop disk.img /mnt/analysis");

  printf("\nForensic acquisition complete\n");

  return 0;
}
