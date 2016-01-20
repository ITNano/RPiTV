/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "Command.h"

void error(const char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, portno = 6789;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  printf("Starting sockets...\n");
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
    error("ERROR opening socket");
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    error("ERROR on binding");

  printf("Started sockets\n");
  while(true){
    printf("Waiting for client....\n");
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
      error("ERROR on accept");

    printf("Everything done, sending greeting and  waiting for messages\n");
    n = write(newsockfd, "Greetings\n", 11);
    if(n < 0)
      error("ERROR sending greeting");

    printf("Greeting sent. Hope he wants to be my friend\n");

    do{
      bzero(buffer,256);
      n = read(newsockfd,buffer,255);
      if (n < 0)
        break;
      else{
        printf("Parsing received data....\n");
        new Command(new string(buffer)).print();
      }

      n = write(newsockfd,"Interesting view!\n",19);
      if (n < 0)
        break;
    }while(true);
    close(newsockfd);
    printf("Client disconnected. Starting over...\n\n");
  }
  close(sockfd);
  return 0; 
}
