#ifndef MENU
#define MENU

#define USIZE 20  //Username Size
#define PSIZE 8   //password size


void clrscrn();
void menu();
void registerUser();
char* stringCat(char request[2],char username[USIZE], char passwrod[PSIZE]);
void loginUser();
void clientMenu(int sockfd,char* username, int admin);
void displayUsers();
void groupChat(char* username);
void privateChat(char* username);
void pullHistory(char* username);
void FTP();
void passwordRequest(char* username);
bool adminOptions(char* username);

#endif
