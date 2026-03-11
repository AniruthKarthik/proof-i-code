#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

void list_directory() {
    printf("\n--- Directory Listing (Current) ---\n");
    DIR *d = opendir(".");
    struct dirent *dir;
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') { // Hide hidden files
                printf("  [File] %s\n", dir->d_name);
            }
        }
        closedir(d);
    }
}

void demo_permissions() {
    const char *test_file = "perm_test.txt";
    printf("\n--- File Permissions Demo ---\n");
    
    int fd = open(test_file, O_CREAT | O_WRONLY, 0644);
    close(fd);
    
    struct stat st;
    stat(test_file, &st);
    printf("  Initial Permissions: %o\n", st.st_mode & 0777);

    printf("  Changing permissions to 400 (Read-only for owner)...\n");
    chmod(test_file, S_IRUSR);

    stat(test_file, &st);
    printf("  Updated Permissions: %o\n", st.st_mode & 0777);

    unlink(test_file);
}

int main() {
    printf("========================================\n");
    printf("  DISK & FILE MANAGEMENT\n");
    printf("========================================\n");

    list_directory();
    demo_permissions();

    return 0;
}
