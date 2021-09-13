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
 int soc,con;
 bzero(&server,sizeof(server));
 server.sin_family=AF_INET;
 server.sin_addr.s_addr=htonl(INADDR_ANY);
 server.sin_port=htons(2015);
 soc=socket(AF_INET,SOCK_STREAM,0);
 con=connect(soc,(struct sockaddr*)&server,sizeof(server));
 printf("client is running\n");
 int pid=fork();
 if(pid==0)
 {
     while(1)
     {
         char b[1024];
         printf("Client Child\n");
         printf("Enter Message:\n");
         fgets(b,sizeof(b),stdin);
         send(soc,b,sizeof(b),0);
     }
 }
 else
 {
     while(1)
     {
         char b1[1024];
         printf("Client Parent\n");
         recv(soc,b1,sizeof(b1),0);
         printf("\nServer:%s",b1);
     }
 }
 return 0;
}