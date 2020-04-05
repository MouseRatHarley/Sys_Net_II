#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include "menu.hpp"

#define RSIZE 1025
#define MAXS 2048
#define PORT 60001 
#define SA struct sockaddr 


using namespace std;




/****************************
**Function 	serv
**Purpose 	Handle HTTP client requests
**Return 	N/A
**Input 	sockfd <-socket connection. .
**
*/

int serv (int sockfd, char* loginfo) 
{ 
	char buff[MAXS]; 
	int connfd; 
	//char *MET[50];
	//char *pch;
	//int i;	
	struct sockaddr_in servaddr;
	char userType[2];
	//printf("[CLIENT] USAGE: GET /src/file.bin\n\n");
	//for (;;) 
	//{ 
		connfd = connect(sockfd, (SA*)&servaddr, sizeof(servaddr)); 
		//clientMenu();
		
		//printf("[CLIENT]: "); 
		//n = 0; 
		//while ((buff[n++] = getchar()) != '\n') ; 
		//cout << loginfo << endl;
		
		bzero(buff,sizeof(buff));

		send(sockfd, loginfo, RSIZE,0);
			
		
		//send(sockfd,"\n",3,0);	
		
		//pch = strtok(buff, " ");
		//i = 0;
		//while (pch != NULL)
		//{
		//	MET[i] = pch;
		//	pch = strtok (NULL," ");
			//printf("TOK[%d]:%s\n",i,MET[i]); //For printing tokens of the http header from client
		//	i++;
		//}
		
		
		bzero(loginfo, sizeof(loginfo)); // clear buffer after sending client response
		bzero(buff,sizeof(buff));

		read(sockfd, buff, sizeof(buff));
		
		
		//cout << "[SERVER]: " << buff << endl;  
		bzero(buff,sizeof(buff));
		read(sockfd,buff,sizeof(buff));
		
		if ((strncmp(buff, "1", 2)) == 0) 
		{ 
			//cout <<"BUFFER READ IN " << buff << endl;
			bzero(buff,sizeof(buff));
			return 1;
		}
		if ((strncmp(buff,"9",1)) == 0)
		{
			return 9;
		}
		else 
		{
			bzero(buff,sizeof(buff));
			return 0;
		}
		//close(connfd);
	//}
} 


int connectToServer()
{
	int sockfd;
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET,SOCK_STREAM, 0);
	if (sockfd == 1)
	{
		cout << "\tSocket Failed\n";
		exit(EXIT_FAILURE);
	}
	else
		cout << "\tSocket Created Successfully\n";

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) !=0)
	{
		cout << "\tConnection Failure\n";
		exit(EXIT_FAILURE);
	}
	else
		cout << "\tConnected at " << PORT << endl;
	
	//serv(sockfd);
	
	//close(sockfd);
	return sockfd;
}

