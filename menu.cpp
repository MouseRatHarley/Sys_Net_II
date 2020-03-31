//libraries
#include <iostream>
#include <stdio.h>
#include "menu.hpp"
#include "user.hpp"
#include "parser.hpp"
#define MAX 255

using namespace std;
void clrscrn()
{
	cout << "\033[2J\033[1;1H";
	cout << "\n\n\n";
	cout << "\tChat Client\n";
	cout << "\tStatus -- \n\n\n\n\n";
	cout << "\t++++++++++++++++++++++++++++++++++++++++++\n";

}

void menu()
{

	char option;
	do
	{
		clrscrn();
		cout << "\tMenu\n";
		cout << "\t++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t1.Login\n";
		cout << "\t2.Register\n";
		cout << "\n";
		cout << "\n";
		cout << "\t0.Exit\n";
		cout << "\t====================================\n\n";
		cout << "\tEnter your selection: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
			case '1':
				cout << "Register\n";
				cout << "\n";
				loginUser();
				break;
			case '2':
				cout << "\n";
				cout << "\n";
				registerUser();
				break;
			case '0':
				cout << "Goodbye.\n";
				break;
				
			default: cout <<option << "is not a valid menu item.\n";
				cout << endl;
		}

	}while (option != '0' );

	
}
void loginUser()
{
	//call login here
	//call server with L0+USERNAME+PASSWORD+
	clrscrn();
	char username[MAX];
	char password[MAX];
	bool userType;
	
	Parser* parser = new Parser();
	cout << "\tLogin\n";
	cout << "\t++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\tEnter Username: ";
	cin >> username;
	clrscrn();
	cout << "\tEnter Password: ";
	cin >> password;
	clrscrn();
	
	userType = parser->checkLoginInfo(username,password);
	
	clientMenu(userType);  //go to main menu for clients
	
}



void registerUser()
{
	//call regiter info here
	//register R0+USERNAME+PASSWORD+
	clrscrn();
	char  username[MAX];
	char  password[MAX];
	cout << "\tRegister User\n";
	cout << "\tEnter Username: ";
	cin >> username;
	clrscrn();
	cout << "\tEnter Password: ";
	cin >> password;
	clrscrn();
	Parser* parser = new Parser();
	parser->registerUser(username,password);
	clrscrn();
	cout << "\n\n\n";
	cout << "\tUser Registered\n\n";

	loginUser();

}


void clientMenu(bool admin)
{

	char option;
		do
		{
			clrscrn();
			cout << "\tClient Menu\n";
			cout << "\t++++++++++++++++++++++++++++++++++++++++++\n";
			cout << "\t1. View Current Members Online\n"; //C0+
			cout << "\t2. Enter Group Chat\n"; //C1+
			cout << "\t3. Enter a private Chat\n"; //C2+
			cout << "\t4. View your chat History\n"; //H0+
			cout << "\t5. File Transfer to a user\n"; //F0+
			cout << "\t6. Change Password\n"; //P0+
			cout << "\t7. Logout\n"; //L0+
			if (admin == true)
			{
				cout << "\t8. Admim\n";//A0+
			}
			cout << "\t0. Return to login\n";
			cout << "\t====================================\n";
			cout << "\tEnter your selection: ";
			cin >> option;
			cout << endl;
			switch (option)
			{
				case '1':
					cout << "\tCurrent Members\n\n";
					displayUsers();
					break;
				case '2':
					cout << "\tGroup Chat\n\n";
					groupChat();
					break;				
				case '3':
					cout << "\tPrivate Chat\n\n";
					privateChat();
					break;
				case '4':
					cout << "\tChat History\n\n";
					pullHistory();
					break;
				case '5':
					cout << "\tFile Transfer\n\n";
					FTP();
					break;
				case '6':
					cout << "\tChange Password\n";
					passwordRequest();
					break;
				case '7':
					cout << "\tLogout\n";
					loginUser();	
					break;
				case '8':
	
					if (admin == true)
					{
						cout << "\tAdministrator\n";
						verifyAdmin();
						break;
					}
					else
						cout <<option << " is not a valid Selection\n";
					break;
				case '0':
					cout << "\tLogin\n";
					loginUser();
					break;
					
				default: cout <<option << " is not a valid Selection\n";
					cout << endl;
			}

		}while (option != '9' );

}



void displayUsers()
{
	
	clrscrn();
	cout << "\t________________________\n";
	cout << "\tCurrent Users in Chat\n\n";
	
	cout << "\tYour Mom\n";
	cout << "\tUser 1\n";
	cout << "\tUser 2\n";
	cout << "\t________________________\n";
	getchar();	
	if (cin.get() == '\n')
	{
		cout << "\tOutta\n\n";
	}

}
void groupChat()
{
	clrscrn();
	cout << "\t_________________________\n";
	cout << "\tWelcome to Group Chat\n";
	cout << "\n\n\n";
	getchar();
	if (cin.get() == '\n')
	{
		cout << "\tChatting \n\n\n";
	}
}

void privateChat()
{
	
	clrscrn();
	cout << "\t_________________________\n";
	cout << "\tWelcome to Private Chat\n";
	cout << "\n\n\n";
	cout << "\tUsers here are:\n\n\n";
	getchar();	
	if (cin.get() == '\n')
	{
		cout << "\tStart Chat\n\n";
	}
}

void pullHistory()
{
	clrscrn();	
	cout << "\t_________________________\n";
	cout << "\tGetting Chat History\n\n";
	getchar();
	if (cin.get() == '\n')
	{
		cout << "\tNo History\n";
	}
}

void FTP()
{
	clrscrn();
	cout << "\t_________________________\n";
	cout << "\tFile Transfer\n\n";
	getchar();
	if (cin.get() == '\n')
	{
		cout << "\tNo File\n";
	}

}
void passwordRequest()
{
	clrscrn();	
	cout << "\t_________________________\n";
	cout << "\tLogin First";
	getchar();
	if (cin.get() == '\n')
	{
		loginUser();
	}

}

void verifyAdmin()
{
	char admin[MAX];
	clrscrn();	
	cout << "\t_________________________\n";
	cout << "\tAre you admin? y/n: ";
	cin >> admin;
	
	if (cin.get() == '\n')
	{
		cout << "\teh im not getting paid for this go ahead\n\n";
	}
	getchar();
}























