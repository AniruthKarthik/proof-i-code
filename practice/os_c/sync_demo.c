#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 3
#define BUFFER_SIZE 5

int shared_buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) pthread_cond_wait(&cond_empty, &mutex);
        
        shared_buffer[count++] = i;
        printf("[Producer] Produced: %d (Buffer Count: %d)\n", i, count);
        
        pthread_cond_signal(&cond_full);
        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) pthread_cond_wait(&cond_full, &mutex);
        
        int item = shared_buffer[--count];
        printf("[Consumer] Consumed: %d (Buffer Count: %d)\n", item, count);
        
        pthread_cond_signal(&cond_empty);
        pthread_mutex_unlock(&mutex);
        usleep(150000);
    }
    return NULL;
}

int main() {
    printf("========================================\n");
    printf("  SYNC: PRODUCER-CONSUMER\n");
    printf("========================================\n");

    pthread_t prod_tid, cons_tid;
    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    printf("\nDemo Completed Successfully.\n");
    return 0;
}
