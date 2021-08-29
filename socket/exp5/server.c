#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <string.h>

int main()
{
  time_t t;
  time(&t);
  char serv_mess[100];
  strcpy(serv_mess, ctime(&t));
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  //DEFINE THE SERVER ADDRESS
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(2011);
  server_address.sin_addr.s_addr = INADDR_ANY;

  //Bind the socket to our specified port and IP address
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
  listen(server_socket, 5);
  int client_socket;
  client_socket = accept(server_socket, NULL, NULL);

  //Send the message
  send(client_socket, serv_mess, sizeof(serv_mess), 0);
  return 0;
}