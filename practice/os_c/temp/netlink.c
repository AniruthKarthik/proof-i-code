#include <linux/netlink.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {

  printf("=== NETLINK IPC DEMO ===\n");

  int sock;

  printf("Creating Netlink socket...\n");

  sock = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);

  if (sock < 0) {
    perror("Socket creation failed");
    return 1;
  }

  printf("Netlink socket successfully created\n");
  printf("File descriptor: %d\n", sock);

  printf("\nThis socket allows kernel-user communication\n");
  printf("Used by tools like Nmap and Wireshark\n");

  close(sock);

  printf("\nSocket closed\n");

  return 0;
}
