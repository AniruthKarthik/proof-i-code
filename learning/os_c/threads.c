#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *threadsDemo() {
  sleep(1);
  printf("msg from threadsDemo\n");
  return NULL;
}

void *backgroundThread(void *arg) {
  for (int i = 0; i < 5; i++) {
    printf("msg from backgroundThread\n");
  }
  return NULL;
}

int basicThreadCreation() {
  pthread_t tid;
  printf("before thread\n");
  pthread_create(&tid, NULL, backgroundThread, NULL);
  // pthread_join(tid, NULL);
  threadsDemo();
  printf("AFTER THREAD\n");
  exit(0);
}

int main() {
  basicThreadCreation();
  return 0;
}
