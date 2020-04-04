#ifndef CLIENT
#define CLIENT

#define PORT 6001
#define SA struct sockaddr

int connectToServer();
void serv (int sockfd, char* loginfo);

#endif
