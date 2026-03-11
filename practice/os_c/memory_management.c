#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

void show_layout() {
    int local_var = 10;
    static int static_var = 20;
    int *heap_var = malloc(sizeof(int));

    printf("\n--- Memory Layout Visualization ---\n");
    printf("  Stack Address:  %p (local_var)\n", (void*)&local_var);
    printf("  Data Address:   %p (static_var)\n", (void*)&static_var);
    printf("  Heap Address:   %p (heap_var)\n", (void*)heap_var);
    free(heap_var);
}

void demo_mprotect() {
    printf("\n--- Memory Protection (mprotect) ---\n");
    size_t pagesize = sysconf(_SC_PAGE_SIZE);
    void *buffer;

    // posix_memalign is the standard way to get page-aligned memory
    if (posix_memalign(&buffer, pagesize, pagesize) != 0) {
        perror("posix_memalign");
        return;
    }

    printf("  Allocated page-aligned buffer at: %p\n", buffer);
    strcpy((char*)buffer, "Initial Data");
    printf("  Current Content: %s\n", (char*)buffer);

    printf("  Setting buffer to READ-ONLY...\n");
    if (mprotect(buffer, pagesize, PROT_READ) == -1) perror("mprotect");

    printf("  (Note: Writing to this now would cause a Segfault)\n");
    
    printf("  Restoring READ-WRITE permissions...\n");
    if (mprotect(buffer, pagesize, PROT_READ | PROT_WRITE) == -1) perror("mprotect restore");
    
    strcat((char*)buffer, " + Appended Data");
    printf("  Updated Content: %s\n", (char*)buffer);

    free(buffer);
}

int main() {
    printf("========================================\n");
    printf("  MEMORY MANAGEMENT\n");
    printf("========================================\n");

    show_layout();
    demo_mprotect();

    return 0;
}
