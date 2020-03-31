//Libraries
#include <iostream>
#include <sstream>
#include <stdio.h>      
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>

//External Files
#include "parser.hpp"
//#include "user.cpp"
#define file "dataBase.txt"

using namespace std;

Parser::Parser(){}



User* Parser::checkLoginInfo(char* username, char* password) {
	
	ifstream fp("dataBase.txt");
	//fp.open();
	char buff2[255];
	
	
	// if no input 
	if ((username == NULL)||(password == NULL)){
		return NULL;
	}
	

	//tokenize
	string buffer;
	if(!fp.is_open())
	{
		return NULL;
	}

	char* token;
	int i = 0;
	while (getline(fp,buffer)) {
		
		strcpy(buff2,buffer.c_str());
		//checks username
		if(i%3==0)
		{
			token = strtok(buff2, "\t\n");
			if(!strcmp(token,username))
			{
				cout<<"USER FOUND"<<endl;
				User* user = new User();
				user->setUsername(username);
				token = strtok(NULL, " \t\n");
				if(!strcmp(token,password))
				{
					cout<<"PASSWORDS MATCH"<<endl;
					user->setPassword(password);
				}
				else
				{
					cout<< "wrong password try again" <<endl;
					delete user;
					fp.close();
					return NULL;
				}
				char* token = strtok(NULL, " \t\n");
				if(token[0]=='A')
				{
					cout<<"WELCOME ADMIN"<<endl;
					user->setAdmin(true);
				}
				else 
				{
					cout<<"WELCOME USER"<<endl;
					user->setAdmin(false);
				}
				user->setAccountNumber(atoi(&token[1]));

				///////////////* TODO SET SOCKET NUMBER */////////////////
				
				
				fp.close();
				user->printUser();
				return user; //username and password match return User class.
			}
			else	//if username does not match the username it progresses to the next one.
			{
			
				token = strtok(buff2, " \t\n");
				token = strtok(buff2, " \t\n");
				i += 2;
			
			}
			
		}
	}
	cout<< "User not found" <<endl;
	fp.close();
	return NULL; //if code gets here that means the user does not exist in the database.

}

User* Parser::registerUser(char* username, char* password) {
	
	
	fstream fp("dataBase.txt");
	//fp.open();
	char buff2[255];
	
	// if no input 
	if ((username == NULL)||(password == NULL)){
		return NULL;
	}
	

	//tokenize
	string buffer;
	if(!fp.is_open())
	{
		return NULL;
	}

	char* token;
	int i = 0;
	while (getline(fp,buffer)) {
		
		strcpy(buff2,buffer.c_str());
		//checks username
		if(i%3==0)
		{
			token = strtok(buff2, "\t\n");
			if(!strcmp(token,username))
			{
				cout<< "Username has been taken" <<endl;
				fp.close();
				return NULL; //Username exists therefore return NULL and let user try again
			}
			else	//if username does not match the username it progresses to the next one.
			{
			
				token = strtok(NULL, " \t\n");
				token = strtok(NULL, " \t\n");
				i += 2;
			
			}
			
		}
	}
	//username is not taken therefore create and populate User class.
	User* user = new User();
	user->setUsername(username);
	/* TO DO IF password checker if the password needs to have certain characters */
	user->setPassword(password);
	user->setAdmin(false);
	/* TO DO add random number generator */
	user->setAccountNumber(456785);	//random account number for now

	return user;
}
