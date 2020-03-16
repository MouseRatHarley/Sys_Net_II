#ifndef USER_
#define USER_

#define MAXARGS 30

class User { 
  private:      
  char* _username;
  char* _password;    
	bool  _admin;                   /* admin identifier        */      
	char* _acountNumber;            /* account number for the user */  
  int   _socketNumber;    
	
	
  public: 
   //CONSTRUCTORS///////////////////////////////////////////////////
   User();
   User (char* username, char* password, char admin, char* accountNumber);
   
   //SETTERS////////////////////////////////////////////////////////
   void setUsername (char *username);
   void setPassword(char *password);
   void setAdmin(bool admin);
   void setAccountNumber(char *accountNumber);

   //DEBUGGING//////////////////////////////////////////////////////
   void printUser();
   
   //GETTERS////////////////////////////////////////////////////////
   char* getUsername();
   char* getPassword();
   bool  getAdmin();
   
   //PRINTERS///////////////////////////////////////////////////////
   void  printFile();
   void  printDir();
   void  grep();
   
   //FLAGS//////////////////////////////////////////////////////////
   
};

#endif
