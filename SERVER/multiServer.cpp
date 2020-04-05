#include <stdio.h> 
#include <string.h> //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h> //close 
#include <arpa/inet.h> //close 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 
#include <iostream>	
#include "multiServer.hpp"
#include "parser.hpp"
#include "user.hpp"
#define TRUE 1 
#define FALSE 0 
#define PORT 60001 
using namespace std;

int server(int argc , char *argv[]) 
{ 
	int opt = TRUE; 
	int master_socket , addrlen , new_socket , client_socket[30] , 
		max_clients = 30 , activity, i , valread , sd; 
	int max_sd; 
	struct sockaddr_in address; 

	char buffer[MAX]; //data buffer of 1K 

	//set of socket descriptors 
	fd_set readfds; 

	//a message 
	char *message = "Im a Server \r\n"; 
	
	User* listOfUsers[max_clients];

	//initialise all client_socket[] to 0 so not checked 
	for (i = 0; i < max_clients; i++) 
	{ 
		client_socket[i] = 0;
		listOfUsers[i] = new User; 
	}	 

	//create a master socket 
	if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	//set master socket to allow multiple connections , 
	//this is just a good habit, it will work without this 
	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,sizeof(opt)) < 0 ) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 

	//type of socket created 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 

	//bind the socket to localhost port 
	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	printf("Listener on port %d \n", PORT); 

	//try to specify maximum of 3 pending connections for the master socket 
	if (listen(master_socket, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 

	//accept the incoming connection 
	addrlen = sizeof(address); 
	puts("Waiting for connections ..."); 

	while(TRUE) 
	{ 
		//clear the socket set 
		FD_ZERO(&readfds); 

		//add master socket to set 
		FD_SET(master_socket, &readfds); 
		max_sd = master_socket; 

		//add child sockets to set 
		for ( i = 0 ; i < max_clients ; i++) 
		{ 
			//socket descriptor 
			sd = client_socket[i]; 

			//if valid socket descriptor then add to read list 
			if(sd > 0) 
				FD_SET( sd , &readfds); 

			//highest file descriptor number, need it for the select function 
			if(sd > max_sd) 
				max_sd = sd; 
		} 

		//wait for an activity on one of the sockets , timeout is NULL , 
		//so wait indefinitely 
		activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL); 

		if ((activity < 0) && (errno!=EINTR)) 
		{ 
			printf("select error"); 
		} 

		//If something happened on the master socket , 
		//then its an incoming connection 
		if (FD_ISSET(master_socket, &readfds)) 
		{ 
			if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
			{ 
				perror("accept"); 
				exit(EXIT_FAILURE); 
			} 

			//inform user of socket number - used in send and receive commands 
			printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(address.sin_addr) , ntohs (address.sin_port)); 

			//send new connection greeting message 
			if( send(new_socket, message, strlen(message), 0) != strlen(message) ) 
			{ 
				perror("send"); 
			} 

			puts("Welcome message sent successfully"); 

			//add new socket to array of sockets 
			for (i = 0; i < max_clients; i++) 
			{ 
				//if position is empty 
				if( client_socket[i] == 0 ) 
				{ 
					client_socket[i] = new_socket; 
					printf("Adding to list of sockets as %d\n" , i); 

					break; 
				} 
			} 
		} 

		//else its some IO operation on some other socket 
		for (i = 0; i < max_clients; i++) 
		{ 
			sd = client_socket[i]; 

			if (FD_ISSET( sd , &readfds)) 
			{ 
				//Check if it was for closing , and also read the 
				//incoming message 
				if ((valread = read( sd , buffer, 1024)) == 0) 
				{ 
					//Somebody disconnected , get his details and print 
					getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen); 
					printf("Host disconnected , ip %s , port %d \n" , 
					inet_ntoa(address.sin_addr) , ntohs(address.sin_port)); 

					//Close the socket and mark as 0 in list for reuse 
					close( sd ); 
					client_socket[i] = 0; 
				} 

				//Echo back the message that came in 
				else
				{ 
					//set the string terminating NULL byte on the end 
					//of the data read 
					
					getpeername(sd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
					
					cout << "USER " << ntohs(address.sin_port);
						
					//buffer[valread] = '\0'; 
					cout << " " << buffer << endl;
					direct(sd,buffer,listOfUsers[sd]);

					send(sd , buffer, strlen(buffer) , 0 ); 
					bzero(buffer,sizeof(MAX));
					//bzero(buffer,MAX);			
					//close(sd);	
				} 
			} 
		} 
	} 

return 0; 
} 

void direct(int sd,char buffer[MAX],User* user)
{
	
	char* MET[50];
	char* pch;
	int i = 0;
	
	Parser* parser = new Parser;
	pch = strtok((char*)buffer,"%");
	while (pch != NULL)
	{
		MET[i] = pch;
		pch = strtok(NULL,"%");
		i++;
	}

	if(strncmp("L0",MET[0],2) == 0)//Login User
	{
		
		user = parser->checkLoginInfo(MET[1],MET[2]);
		if (user != NULL)//good username and password
		{
			//cout << "LOGIN OK\n";
			if(user->getAdmin() == 1)
			{	
				//cout << "1\n\n";
				send(sd, "1", sizeof(2), 0);
			}
			else
			{
				//cout << "0\n\n";
				send(sd, "0", sizeof(2),0);
			}
			bzero(buffer,sizeof(MAX));
		
		}
		else//bad login attempt let user know
		{
			delete user;
			send(sd,"9",sizeof(2),0);
		}
	
	}
	if(strncmp("R0",MET[0],2) == 0)//Register User
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			delete user;
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	/*
	if(strncmp("C0",MET[0],2) == 0)//Online members
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	if(strncmp("C1",MET[0],2) == 0)//Public Chat
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	if(strncmp("C2",MET[0],2) == 0)//private Chat
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	if(strncmp("H0",MET[0],2) == 0)//Chat History
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	if(strncmp("F0",MET[0],2) == 0)//File Transfer
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	if(strncmp("P0",MET[0],2) == 0)//Change Password
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	if(strncmp("A0",MET[0],2) == 0)//Ban Member
	{

		user = parser->registerUser(MET[1],MET[2]);
		if (user != NULL)
		{
			send(sd,"1",sizeof(2),0);

			bzero(buffer,sizeof(MAX));
		}
		else
		{
			send(sd,"0",sizeof(2),0);
		}
		bzero(buffer,sizeof(MAX));

	}
	*/
}


















