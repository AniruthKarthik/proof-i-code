#include <stdio.h>  
#include <stdlib.h> // for exit 
#include <string.h> // for memset, strlen
#include <unistd.h> // for close()
#include <sys/socket.h> // for socket(), connect(), send(), recv()
#include <netinet/in.h> // for sockaddr_in
#include <arpa/inet.h> // for inet_pton()


int main(){
    int sockfd;

    // create socket (ipv4-sock_stream-0)
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
}
