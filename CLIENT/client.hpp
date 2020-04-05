#ifndef CLIENT
#define CLIENT

#define PORT 6001
#define SA struct sockaddr

int connectToServer();
int serv (int sockfd, char* loginfo);
void chat(int sockfd, char* loginfo);
#endif
