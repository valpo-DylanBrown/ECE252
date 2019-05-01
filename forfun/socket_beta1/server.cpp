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
  const char *yikes = "I do not understand.";

  const char* q1 = "How are you?";
  const char* q2 = "What are you doing?";
  const char* q3 = "What's your favorite color?";
  const char* q4 = "When's your birthday?";
  const char* q5 = "What's your job?";
  const char* q6 = "What's your favorite joke?";
  const char* q7 = "What's your favorite season?";
  const char* q8 = "Where were you born?";
  const char* q9 = "Who made you?";
  const char* q10 = "What is your name?";

  const char *a1 = "I am good!";
  const char *a2 = "I am gaining sentience!";
  const char *a3 = "My favorite color is blue!";
  const char *a4 = "April 4th, 2019";
  const char *a5 = "Going Beep-Boop-Beep!";
  const char *a6 = "Why did 7 eat 9? --- It needed 3^2 meals a day!";
  const char *a7 = "The best season is summer!";
  const char *a8 = "Brandt Hall is my home!";
  const char *a9 = "Dylan Brown created me!";
  const char *a10 = "My name is Ari!";
  int socketID = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in serverAddr;

  bzero((char*)&serverAddr, sizeof(serverAddr));

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  bind(socketID, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  listen(socketID, maxBackLog);

  int finished = 0;
  while(!finished)
  {
    struct sockaddr_storage serverStorage;
    socklen_t addr_size   = sizeof serverStorage;

    int  newSocket = accept(socketID, (struct sockaddr*)&serverStorage, &addr_size);
    char buffer[SERVER_BUFFER_SIZE];
    int  get = read(newSocket, buffer, SERVER_BUFFER_SIZE - 1);

    buffer[get] = '\0';
    fprintf(stdout, "%s\n", buffer);
    //write(newSocket, "OK", 2);
    if(strcmp(buffer, q1) == 0) {
      write(newSocket , a1 , strlen(a1));
    }
    else if(strcmp(buffer, q2) == 0) {
      write(newSocket , a2 , strlen(a2));
    }
    else if(strcmp(buffer, q3) == 0) {
      write(newSocket , a3 , strlen(a3));
    }
    else if(strcmp(buffer, q4) == 0) {
      write(newSocket , a4 , strlen(a4));
    }
    else if(strcmp(buffer, q5) == 0) {
      write(newSocket , a5 , strlen(a5));
    }
    else if(strcmp(buffer, q6) == 0) {
      write(newSocket , a6 , strlen(a6));
    }
    else if(strcmp(buffer, q7) == 0) {
      write(newSocket , a7 , strlen(a7));
    }
    else if(strcmp(buffer, q8) == 0) {
      write(newSocket , a8 , strlen(a8));
    }
    else if(strcmp(buffer, q9) == 0) {
      write(newSocket , a9 , strlen(a9));
    }
    else if(strcmp(buffer, q10) == 0) {
      write(newSocket , a10 , strlen(a10));
    }
    else if(strcmp(buffer, "stop") == 0){
      write(newSocket , "OK, nice chat, bye!" , 19);
      finished = 1;
    }
    else{
      write(newSocket , yikes , strlen(yikes));
    }
    //write(newSocket , hello , strlen(hello));
    //fprintf(stdout,"Hello message sent\n");
    fprintf(stdout, "Message Complete\n");

    close(newSocket);
  }
  close(socketID);
}
