#include <iostream>
#include <sstream>
#include <stdio.h>      
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstddef> 
#include <cstring>  
#include <sys/types.h> 
#include <unistd.h>
#include <time.h>
#include <thread>
#include <mutex>          // std::mutex

#include "client.hpp"
#include "menu.hpp"

/*********************
**Code Developed: Jarrod Resmondo
**		  Shane Bolding
**4/5/2020
**COP4635 Project 2
**
*/


/****************************
**Function: Main file. This file calls the menu function
**for the client/User.
**
*/

#define BUFFER_SIZE 1024


using namespace std;


int main(int argc, char** argv) 
{	
	
	menu();
	//connectToServer();
	//Parser* parser = new Parser();
	//parser->registerUser("shane","123456");
	//parser->checkLoginInfo("shane","123456"); 			####IMPLEMENTED IN MENU
	//parser->registerUser("XxSniperKillerxX","8560");   		####IMPLEMENTED IN MENU
	//parser->registerUser("DUDEBRO","8560");			####
	//parser->changePassword("XxSniperKillerxX","8560","7895");	####IMPLEMENTED IN MENU
	//parser->deleteUser("XxSniperKillerxX","8560"); 		####
	//parser->banUser("DUDEBRO","8560");				####
	//parser->chatHistory("godwashere","DoodleBob");		//	####	
	
	return 0;
}
