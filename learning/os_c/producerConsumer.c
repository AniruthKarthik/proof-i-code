#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 3
int buffer[BUFFER];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg) {
  int item;

  while (1) {
    item = rand() % 10;
    printf("produced: %d \n", item);

    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[in] = item;
    in = (in + 1) % BUFFER;

    sem_post(&mutex);
    sem_post(&full);

    sleep(1);
  }
}

void *consumer(void *arg) {
  int item;

  while (1) {
    sem_wait(&full);
    sem_wait(&mutex);

    item = buffer[out];
    out = (out + 1) % BUFFER;

    sem_post(&mutex);
    sem_post(&empty);

    printf("consumed %d\n", item);
    sleep(2);
  }
}

int main() {
  pthread_t p, c;

  sem_init(&empty, 0, BUFFER);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);

  pthread_create(&p, NULL, producer, NULL);
  pthread_create(&c, NULL, consumer, NULL);

  pthread_join(p, NULL);
  pthread_join(c, NULL);

  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&mutex);

  return 0;
}
