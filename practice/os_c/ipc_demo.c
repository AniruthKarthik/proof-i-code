#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <mqueue.h>

#define SHM_NAME "/os_demo_shm"
#define SHM_SIZE 1024
#define MQ_NAME  "/os_demo_mq"

void run_pipe_demo() {
    int pipefd[2];
    char buffer[100];
    printf("\n--- Sub-Demo 1: Anonymous Pipe ---\n");
    if (pipe(pipefd) == -1) { perror("pipe"); exit(1); }

    if (fork() == 0) {
        close(pipefd[0]);
        const char *msg = "Pipe Data Stream";
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
        exit(0);
    } else {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("[Parent] Pipe Received: '%s'\n", buffer);
        close(pipefd[0]);
        wait(NULL);
    }
}

void run_shm_demo() {
    printf("\n--- Sub-Demo 2: POSIX Shared Memory ---\n");
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    char *ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (fork() == 0) {
        sprintf(ptr, "Shared Memory Buffer populated by PID %d", getpid());
        munmap(ptr, SHM_SIZE);
        close(shm_fd);
        exit(0);
    } else {
        wait(NULL);
        printf("[Parent] SHM Read: '%s'\n", ptr);
        munmap(ptr, SHM_SIZE);
        close(shm_fd);
        shm_unlink(SHM_NAME);
    }
}

void run_mq_demo() {
    printf("\n--- Sub-Demo 3: POSIX Message Queue ---\n");
    struct mq_attr attr = { .mq_flags = 0, .mq_maxmsg = 10, .mq_msgsize = 256, .mq_curmsgs = 0 };
    mqd_t mq = mq_open(MQ_NAME, O_CREAT | O_RDWR, 0644, &attr);
    
    if (fork() == 0) {
        const char *msg = "Message Queue Packet";
        mq_send(mq, msg, strlen(msg) + 1, 0);
        printf("[Child]  Sent message to MQ.\n");
        mq_close(mq);
        exit(0);
    } else {
        char buffer[256];
        wait(NULL);
        mq_receive(mq, buffer, 256, NULL);
        printf("[Parent] MQ Received: '%s'\n", buffer);
        mq_close(mq);
        mq_unlink(MQ_NAME);
    }
}

int main() {
    printf("========================================\n");
    printf("  IPC DEMONSTRATION\n");
    printf("========================================\n");
    run_pipe_demo();
    run_shm_demo();
    run_mq_demo();
    return 0;
}
