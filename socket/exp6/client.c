#include<stdio.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
int main()
{
 struct sockaddr_in server,client;
 char buffer[1000];
 int soc,con,acc;
 bzero(&server,sizeof(server));
 server.sin_family=AF_INET;
 server.sin_addr.s_addr=htonl(INADDR_ANY);
 server.sin_port=htons(1551);
 soc=socket(AF_INET,SOCK_STREAM,0);
 con=connect(soc,(struct sockaddr*)&server,sizeof(server));
printf("client is running\n");
while(1)
{
bzero(&buffer,sizeof(buffer));
printf("Enter Message for server\n");
fgets(buffer,sizeof(buffer),stdin);
send(soc,buffer,sizeof(buffer),0);
recv(soc,buffer,sizeof(buffer),0);
printf("\nMessage Received:-%s",buffer);
}
return 0;
}