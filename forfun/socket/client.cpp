#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#define PORT 8080
#define CLIENT_BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
  int valRead;

  /*const char* q1 = "How are you?";
  const char* q2 = "What are you doing?";
  const char* q3 = "What's your favorite color?";
  const char* q4 = "When's your birthday?";
  const char* q5 = "What's your job?";
  const char* q6 = "What's your favorite joke?";
  const char* q7 = "What's your favorite season?";
  const char* q8 = "Where were you born?";
  const char* q9 = "Who made you?";
  const char* q10 = "What is your name?";*/

    if (argc != 2)
    {
        fprintf(stderr, "Usage: client <host>\n");
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
    bool isStopped = false;
    for(int i = 0; i<3; i++){
      char* message = new char[CLIENT_BUFFER_SIZE];
      //std::cout << "Hello" << std::endl;
      std::cout << "Please enter the message you want to send: " << std::endl;
      std::cin.getline(message,1024);
      //std::cout << "Hello" << std::endl;
      write(socketId, message, strlen(message));
      char buffer[CLIENT_BUFFER_SIZE];
      size_t get = read(socketId, buffer, CLIENT_BUFFER_SIZE - 1);
      buffer[get] = '\0';
      fprintf(stdout, "%s %s\n", "Response from server:", buffer);
      if(strcmp(message, "stop") == 0){
        isStopped = true;
      }
    }

    close(socketId);
}
