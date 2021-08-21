#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
int main()
{
    struct sockaddr_in server, client;
    char message[1000];
    char reply[1000] = "hello this is the server !!";
    int soc, bd;
    socklen_t len;
    len = sizeof(client);
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(2025);
    soc = socket(AF_INET, SOCK_DGRAM, 0);
    bd = bind(soc, (struct sockaddr *)&server, sizeof(server));
    printf("server is running\n");
    while (1)
    {
        bzero(&message, sizeof(message));
        recvfrom(soc, message, sizeof(message), 0,(struct sockaddr*)&client,&len);
        printf("Message Received from client:-%s\n", message);
        sendto(soc, reply, sizeof(reply), 0,(struct sockaddr*)&client,sizeof(client));
        printf("reply sent to client: %s\n", reply);
    }
    return 0;
}