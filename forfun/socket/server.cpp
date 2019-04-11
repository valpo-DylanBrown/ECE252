/*#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#define PORT 8080

using namespace std;

void checkSocketFailure(int server_fd){
  if((server_fd == socket(AF_INET, SOCK_STREAM, 0)) == 0){
    perror("socket failure");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char const *argv[]){
  int server_fd, new_socket, valRead;
  struct sockaddr_in address;
  int opt =1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  const char *hello = "Hello from server";

  checkSocketFailure(server_fd);

  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    perror("setsockopt failure");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
  if (listen(server_fd, 3) < 0){
       perror("listen");
       exit(EXIT_FAILURE);
   }
   if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
       perror("accept");
       exit(EXIT_FAILURE);
   }
   valRead = read( new_socket , buffer, 1024);
   printf("%s\n",buffer );
   send(new_socket , hello , strlen(hello) , 0 );
   printf("Hello message sent\n");
   return 0;

}*/

#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define SERVER_BUFFER_SIZE 1024

static const int maxBackLog = 5;

int main(){
  int socketID = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in serverAddr;

  bzero((char*)&serverAddr, sizeof(serverAddr));

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  bind(socketID, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  listen(socketID, maxBackLog);

  int finished    = 0;
  while(!finished)
  {
    struct sockaddr_storage serverStorage;
    socklen_t addr_size   = sizeof serverStorage;

    int  newSocket = accept(socketID, (struct sockaddr*)&serverStorage, &addr_size);
    char buffer[SERVER_BUFFER_SIZE];
    int  get = read(newSocket, buffer, SERVER_BUFFER_SIZE - 1);

    buffer[get] = '\0';
    fprintf(stdout, "%s\n", buffer);
    write(newSocket, "OK", 2);
    fprintf(stdout, "Message Complete\n");

    close(newSocket);
  }
  close(socketID);
}
