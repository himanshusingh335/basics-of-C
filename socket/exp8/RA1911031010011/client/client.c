#include<stdio.h>
#include<unistd.h>
#include<time.h>
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
 server.sin_port=htons(2012);
 soc=socket(AF_INET,SOCK_STREAM,0);
 con=connect(soc,(struct sockaddr*)&server,sizeof(server));
printf("client is running\n");

while(1)
{
char b1[1024];
printf("Enter Filename:\n");
scanf("%s",b1);
send(soc,b1,strlen(b1)+1,0);
char b2[1024];
recv(soc,b2,sizeof(b2),0);
printf("File:%s\n",b2);
}
return 0;
 }
