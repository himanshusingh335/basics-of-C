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
 int soc,bd,acc;
 socklen_t len;
 len=sizeof(client);
 bzero(&server,sizeof(server));
 server.sin_family=AF_INET;
 server.sin_addr.s_addr=htonl(INADDR_ANY);
 server.sin_port=htons(2015);
 soc=socket(AF_INET,SOCK_STREAM,0);
 bd=bind(soc,(struct sockaddr*)&server,sizeof(server));
 listen(soc,5);
 printf("server is running\n");
 acc=accept(soc,(struct sockaddr*)&client,&len);
 int pid=fork();
 if(pid==0)
 {
     while(1)
     {
         char b2[1024];
         printf("Server Child\n");
         recv(acc,b2,sizeof(b2),0);
         printf("Client: %s",b2);
     }
 }
 else
 {
     while(1)
     {
         char b1[1024];
         printf("Server Parent\n");
         fgets(b1,sizeof(b1),stdin);
         send(acc,b1,sizeof(b1),0);
     }
 }
 return 0;
}