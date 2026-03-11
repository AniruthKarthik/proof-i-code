#include <pthread.h>
#include <stdio.h>

int counter = 0;

pthread_mutex_t lock;

void *increment(void *arg) {

  for (int i = 0; i < 100000; i++) {

    pthread_mutex_lock(&lock);

    counter++;

    pthread_mutex_unlock(&lock);
  }

  return NULL;
}

int main() {

  printf("=== MUTEX SYNCHRONIZATION DEMO ===\n");

  pthread_t t1, t2;

  pthread_mutex_init(&lock, NULL);

  printf("Initial counter value: %d\n", counter);

  printf("Creating two threads...\n");

  pthread_create(&t1, NULL, increment, NULL);
  pthread_create(&t2, NULL, increment, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Threads finished\n");
  printf("Final counter value: %d\n", counter);

  pthread_mutex_destroy(&lock);

  return 0;
}
