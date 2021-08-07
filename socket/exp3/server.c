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
    int soc, bd, acc;
    socklen_t len;
    len = sizeof(client);
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(1999);
    soc = socket(AF_INET, SOCK_STREAM, 0);
    bd = bind(soc, (struct sockaddr *)&server, sizeof(server));
    listen(soc, 5);
    printf("server is running\n");
    acc = accept(soc, (struct sockaddr *)&client, &len);
    while (1)
    {
        bzero(&message, sizeof(message));
        recv(acc, message, sizeof(message), 0);
        printf("Message Received from client:-%s\n", message);
        send(acc, reply, sizeof(reply), 0);
        printf("reply sent to client: %s\n", reply);
    }
    return 0;
}