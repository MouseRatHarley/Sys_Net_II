//libraries
#include <iostream>
#include <stdio.h>

using namespace std;

void menu()
{

	char option;
	do
	{
		cout << "  Menu\n";
		cout << "  ++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "  1.Login\n";
		cout << "  2.Register\n";
		cout << "  \n";
		cout << "  \n";
		cout << "  \n";
		cout << "  0.  Exit\n";
		cout << "  ====================================\n";
		cout << "  Enter your selection: ";
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
				return(EXIT_SUCCESS);
				break;
				
			default: cout <<option << "is not a valid menu item.\n";
				cout << endl;
		}

	}while (option != '5' );

	
}
void loginUser()
{
	//call login here
	cout << "Enter Login info\n";
	bool userType;
	cin >> userType;
	clientMenu(userType); //go to main menu for clients

}



void registerUser()
{
	//call regiter info here
	cout << "Register User\n";
	cout << "Enter Username\n";
	cout << "Enter Password\n";
	
	cout << "\n\n\n";
	cout << "User Registered\n\n";



	loginUser();

}



void clientMenu(bool admin)
{


char option;
	do
	{
		cout << "  Menu\n";
		cout << "  ++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "  1.View Current Members Online\n";
		cout << "  2.Enter Group Chat\n";
		cout << "  3. Enter a private Chat\n";
		cout << "  4. View your chat History\n";
		cout << "  5. File Transfer to a user\n";
		cout << "  6. Change Password\n";
		cout << "  7. Logout\n";
		if (admin == true)
		{
			cout << "  8. Admim\n";
		}
		cout << "  0. Return to login\n";
		cout << "  ====================================\n";
		cout << "  Enter your selection: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
			case '1':
				cout << "Current Members\n\n";
				//displayUsers();
				break;
			case '2':
				cout << "Group Chat\n\n";
				//groupChat();
				break;				
			case '3':
				cout << "Private Chat\n\n";
				//privateChat();
				break;
			case '4':
				cout << "Chat History\n\n";
				//pullHistory();
				break;
			case '5':
				cout << "File Transfer\n\n";
				//FTP();
				break;
			case '6':
				cout << "Change Password\n";
				//passwordRequest();
				break;
			case '7':
				cout << "Logout\n";
				//loginUser();	
				break;
			if (admin == true)
			{
				case '8':
				cout << "Administrator\n";
				//verifyAdmin();
				break;
			}						
			case '0':
				cout << "Login\n";
				loginUser();
				break;
				
			default: cout <<option << "is not a valid menu item.\n";
				cout << endl;
		}

	}while (option != '' );

}
