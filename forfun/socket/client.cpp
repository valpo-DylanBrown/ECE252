/*#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>

#define PORT 8080

using namespace std;

int main(int argc, char const *argv[]){
  struct sockaddr_in address;
  int sock = 0, valRead;
  struct sockaddr_in serv_addr;
  const char* hello = "Hello from Client";
  char buffer[1024] = {0};
  if((sock = socket(AF_INET, SOCK_STREAM,  0)) < 0){
    cout << endl << "Socket Creation Error" << endl;
    return -1;
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);

  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
      cout << endl << "Invalid Address / Address Not Supported" << endl;
      return -1;
    }
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    cout << endl << "Connection failed" << endl;
    return -1;
  }
  send(sock, hello, strlen(hello),0);
  cout << "Hello Sent" << endl;
  valRead = read(sock, buffer, 1024);
  cout << buffer << endl;
  return 0;
}*/

#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define CLIENT_BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: client <host> <Message>\n");
        exit(1);
    }

    int socketId = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    socklen_t addrSize = sizeof(serverAddr);
    bzero((char*)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    connect(socketId, (struct sockaddr*)&serverAddr, addrSize);

    write(socketId, argv[2], strlen(argv[2]));

    shutdown(socketId, SHUT_WR);

    char buffer[CLIENT_BUFFER_SIZE];
    size_t get = read(socketId, buffer, CLIENT_BUFFER_SIZE - 1);

    buffer[get] = '\0';
    fprintf(stdout, "%s %s\n", "Response from server", buffer);

    close(socketId);
}
