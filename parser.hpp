#ifndef PARSER_
#define PARSER_

#include "user.hpp"

class Parser{

	public:
		Parser();
		
		User* checkLoginInfo(char* username, char* password);
		User* registerUser(char* username, char* password);

};

#endif
