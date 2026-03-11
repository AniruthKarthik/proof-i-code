#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {

  printf("=== MMAP DEMO ===\n");

  int fd = open("test.txt", O_RDONLY);

  if (fd < 0) {
    perror("File open failed");
    return 1;
  }

  printf("File opened successfully\n");

  off_t size = lseek(fd, 0, SEEK_END);

  printf("File size: %ld bytes\n", size);

  char *data = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);

  printf("File mapped into memory\n");

  printf("\nFirst 100 characters:\n\n");

  for (int i = 0; i < 100 && i < size; i++)
    printf("%c", data[i]);

  printf("\n\nUnmapping memory\n");

  munmap(data, size);

  close(fd);

  printf("Demo completed\n");

  return 0;
}
