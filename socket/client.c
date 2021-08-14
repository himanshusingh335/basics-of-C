#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
int main()
{
    struct sockaddr_in server, client;
    char message[1000];
    char reply[1000];
    int soc, con;
    socklen_t len;
    len = sizeof(server);
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(2025);
    soc = socket(AF_INET, SOCK_DGRAM, 0);
    printf("client is running\n");
    while (1)
    {
        bzero(&message, sizeof(message));
        printf("Enter Message: ");
        fgets(message, sizeof(message), stdin);
        printf("\n");
        sendto(soc, message, sizeof(message), 0,(struct sockaddr*)&server,sizeof(server));
        printf("Message sent to server: %s\n", message);
        if (recvfrom(soc, reply, sizeof(reply), 0,(struct sockaddr*)&server,&len) < 0)
        {
            printf("Recv Failed\n");
        }
        printf("Reply Received from server:-%s\n", reply);
    }
    return 0;
}