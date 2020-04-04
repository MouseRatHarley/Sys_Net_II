#ifndef MENU
#define MENU

void clrscrn();
void menu();
void registerUser();
void loginUser();
void clientMenu(char* username, bool admin);
void displayUsers();
void groupChat(char* username);
void privateChat(char* username);
void pullHistory(char* username);
void FTP();
void passwordRequest(char* username);
bool verifyAdmin(char* username);

#endif
