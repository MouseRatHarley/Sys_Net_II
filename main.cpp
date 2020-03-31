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

#include "menu.hpp"
#include "user.hpp"
#include "parser.hpp"

#define BUFFER_SIZE 1024

//g++ -std=c++11 -pthread Untitled1.cpp 
//with threads: Time taken by program is : 100.000000 sec

using namespace std;


int main(int argc, char** argv) 
{	
	
	menu();
	
	Parser* parser = new Parser();
	parser->checkLoginInfo("shane","1234");
	parser->registerUser("XxSniperKillerxX","8560");
	
	return 0;
}
