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
 server.sin_port=htons(2012);
 soc=socket(AF_INET,SOCK_STREAM,0);
 bd=bind(soc,(struct sockaddr*)&server,sizeof(server));
 listen(soc,5);
 printf("server is running\n");
 acc=accept(soc,(struct sockaddr*)&client,&len);
while(1)
{
char b1[1024];
recv(acc,b1,sizeof(b1),0);
FILE *f=fopen(b1,"r");
char b2[1024];
fread(b2,sizeof(b2),1,f);
fclose(f);
send(acc,b2,sizeof(b2),0);
printf("File send\n");
}
return 0;
 }
