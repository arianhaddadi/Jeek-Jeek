#include "functions.hpp"

int main () 
{
	Network network;
	string command;
	while ( command != "quit" ) { 
		cout << "you need to signup/login to us the system" << endl << "your command:" ;
		cin >> command ;
		try { 
			network.choose_action (command) ;
		}
		catch ( string exception ) {
			if ( exception == "logout" ) {
				cout << "you got logged out" << endl;
				continue ;
			}
			cout << "wrong command.PLease try again:" << endl;
			continue;
		}
	}
	return 0;
}