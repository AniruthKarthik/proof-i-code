#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define Nreaders 5
#define Nwriters 2

sem_t mutex;
sem_t resrc;
sem_t readCountMutex;
int readCnt = 0;

void *reader(void *arg) {
  int readerId = *(int *)arg;
  while (1) {
    sem_wait(&readCountMutex);
    readCnt++;
    if (readCnt == 1) {
      sem_wait(&resrc);
    }
    sem_post(&readCountMutex);

    printf("reader %d is reading\n", readerId);
    sleep(rand() % 3);

    sem_wait(&readCountMutex);
    readCnt--;
    if (readCnt == 0) {
      sem_post(&resrc);
    }
    sem_post(&readCountMutex);

    printf("reader %d finished reading\n", readerId);
    sleep(rand() % 3);
  }
}

void *writer(void *arg) {
  int writerId = *(int *)arg;

  while (1) {
    sem_wait(&mutex);
    sem_wait(&resrc);
    printf("writer %d is writing\n", writerId);
    sleep(rand() % 3);
    sem_post(&resrc);
    sem_post(&mutex);

    printf("writer %d finished writing\n", writerId);
    sleep(rand() % 3);
  }
}

int main() {
  pthread_t readerT[Nreaders], writerT[Nwriters];
  int readerIds[Nreaders], writerIds[Nwriters];

  srand(time(NULL));

  sem_init(&mutex, 0, 1);
  sem_init(&resrc, 0, 1);
  sem_init(&readCountMutex, 0, 1);

  for (int i = 0; i < Nreaders; i++) {
    readerIds[i] = i + 1;
    pthread_create(&readerT[i], NULL, reader, (void *)&readerIds[i]);
  }

  for (int i = 0; i < Nwriters; i++) {
    writerIds[i] = i + 1;
    pthread_create(&writerT[i], NULL, writer, (void *)&writerIds[i]);
  }

  for (int i = 0; i < Nreaders; i++) {
    pthread_join(readerT[i], NULL);
  }

  for (int i = 0; i < Nwriters; i++) {
    pthread_join(writerT[i], NULL);
  }
}
