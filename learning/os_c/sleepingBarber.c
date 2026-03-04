#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define Ncust 10
#define Nchair 5

sem_t barberReady;
sem_t customerReady;
sem_t accessSeats;
int noFreeSeats = Nchair;

void *barber(void *arg) {
  while (1) {
    sem_wait(&customerReady);
    sem_wait(&accessSeats);
    noFreeSeats++;
    sem_post(&barberReady);
    sem_post(&accessSeats);
    printf("Barber is cutting hair\n");
    sleep(rand() % 3);
  }
}

void *customer(void *arg) {
  int custID = *(int *)arg;

  sem_wait(&accessSeats);

  if (noFreeSeats > 0) {
    noFreeSeats--;
    sem_post(&customerReady);
    sem_post(&accessSeats);
    sem_wait(&barberReady);
    printf("customer %d is getting a haircut\n", custID);

    sleep(rand() % 3);
  } else {
    sem_post(&accessSeats);
    printf("customed %d left the shop\n ", custID);
  }
  return NULL;
}

int main() {
  pthread_t barberT, customerT[Ncust];
  int custIDs[Ncust];

  sem_init(&barberReady, 0, 0);
  sem_init(&customerReady, 0, 0);
  sem_init(&accessSeats, 0, 1);

  pthread_create(&barberT, NULL, barber, NULL);

  for (int i = 0; i < Ncust; i++) {
    custIDs[i] = i + 1;
    pthread_create(&customerT[i], NULL, customer, (void *)&custIDs[i]);
    sleep(rand() % 2);
  }

  for (int i = 0; i < Ncust; i++) {
    pthread_join(customerT[i], NULL);
  }

  pthread_cancel(barberT);
  pthread_join(barberT, NULL);

  return 0;
}
