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

void chat(int sockfd, char* message)
{
	char buff[MAXS]; 
	int connfd; 
	//char *MET[50];
	char *pch;
	char type[4];
	int i,n;	
	struct sockaddr_in servaddr;
	char userType[2];
	for (;;) 
	{ 
		strcpy(type,"C1%");

		connfd = connect(sockfd, (SA*)&servaddr, sizeof(servaddr)); 
			
		printf("[CLIENT]: "); 
		n = 0; 
		
		while ((buff[n++] = getchar()) != '\n') ; 
		
		strcat(type,buff);
		strcat(type,"%");
		send(sockfd, type, RSIZE, 0);
		
		bzero(type,sizeof(type));
		//bzero(buff,sizeof(buff));
						
				
		read(sockfd, buff, sizeof(buff)) != NULL
		
			cout << "[SERVER]: " << buff << endl;  
			//bzero(buff,sizeof(buff));
			//close(connfd);
		

	}
} 




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
		
		connfd = connect(sockfd, (SA*)&servaddr, sizeof(servaddr)); 
		
		bzero(buff,sizeof(buff));

		send(sockfd, loginfo, RSIZE,0);
		
		//bzero(loginfo, sizeof(loginfo)); // clear buffer after sending client response
		bzero(buff,sizeof(buff));
		
		if (read(sockfd, buff, sizeof(buff))!=NULL)
		{
		
			
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

