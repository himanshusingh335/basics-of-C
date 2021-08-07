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
    server.sin_port = htons(1999);
    soc = socket(AF_INET, SOCK_STREAM, 0);
    con = connect(soc, (struct sockaddr *)&server, sizeof(server));
    printf("client is running\n");
    while (1)
    {
        bzero(&message, sizeof(message));
        printf("Enter Message: ");
        fgets(message, sizeof(message), stdin);
        printf("\n");
        send(soc, message, sizeof(message), 0);
        printf("Message sent to server: %s\n", message);
        if (recv(soc, reply, sizeof(reply), 0) < 0)
        {
            printf("Recv Failed\n");
        }
        printf("Reply Received from server:-%s\n", reply);
    }
    return 0;
}