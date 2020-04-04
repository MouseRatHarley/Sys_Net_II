#ifndef CLIENT
#define CLIENT

#define MAX 2048
#define PORT 6001
#define SA struct sockaddr

void connectToServer();
void serv (int sockfd);

#endif
