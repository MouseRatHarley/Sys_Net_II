//Libraries
#include <iostream>
#include <sstream>
#include <stdio.h>      
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//External Files
#include "parser.hpp"
//#include "user.cpp"
#define file "dataBase.txt"

Parser::Parser(){}



User* Parser::checkLoginInfo(char* username, char* password) {
	
	
	// if no input 
	if ((username == NULL)||(password == NULL) {
		return NULL;
	}
	
	dataBase = fopen(file);
	//tokenize
	char* token = strtok(dataBase, " \t\n");

	if (token == NULL) {
		return NULL;
	}


	
	int i = 0;
	while (token != NULL) {
		
		//checks username
		if(i%3==0)
		{
			if(strcmp(token,username))
			{
				User* user = new User();
				user->setUsername(username);
				char* token = strtok(dataBase, " \t\n");
				if(strcmp(token,password))
				{
					user->setPassword(password);
				}
				else
				{
					cout<< "wrong password try again" <<endl;
					delete user;
					fclose(dataBase);
					return NULL;
				}
				char* token = strtok(dataBase, " \t\n");
				if(token[0]=='A')
				{
					user->setAdmin(true);
				}else user->setAdmin(false);
				user->setAccountNumber(token[1]);

				///////////////* TODO SET SOCKET NUMBER */////////////////
				fclose(dataBase);
				user->printUser();
				return user; //username and password match return User class.
			}
			else	//if username does not match the username it progresses to the next one.
			{
			
				char* token = strtok(dataBase, " \t\n");
				char* token = strtok(dataBase, " \t\n");
				i += 2;
			
			}
			
		}
	}
	cout<< "User not found" <<endl;
	fclose(dataBase)
	return NULL; //if code gets here that means the user does not exist in the database.
}

User* Parser::registerUser(char* username, char* password) {
	
	
	// if no input 
	if ((username == NULL)||(password == NULL) {
		return NULL;
	}
	
	//tokenize
	char* token = strtok(dataBase, " \t\n");

	if (token == NULL) {
		return NULL;
	}


	
	int i = 0;
	while (token != NULL) {
		
		//checks username
		if(i%3==0)
		{
			if(strcmp(token,username))
			{
				
				cout<< "Username has been taken" <<endl;

				return NULL; //Username exists therefore return NULL and let user try again.

			}
			else	//if username does not match the username it progresses to the next one.
			{
			
				char* token = strtok(dataBase, " \t\n");
				char* token = strtok(dataBase, " \t\n");
				i += 2;
			
			}
			
		}
	}
	//username is not taken therefore create and populate User class.
	User* user = new User();
	user->setUsername(username);
	/* TO DO password checker if the password needs to have certain characters */
	user->setPassword(password);
	user->setAdmin(false);
	/* TO DO add random number generator */
	user->setAccountNumber("x743574");	//random account number for now

}
