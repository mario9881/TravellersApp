#include<iostream>
#include"App.h"
#include"String.h"
using namespace std;

int main(){
    App app;
    bool weHaveEnteredExit = false;
    String command;

    while (!weHaveEnteredExit) {
        cin >> command;
        if (command == "create_account") {
            app.createAccount();
        }
        else if (command == "add_trip") {
            app.addTrip();
        }
        else if (command == "invite") {
            app.invite();
        }
        else if (command == "accept") {
            app.accept();
        }
        else if (command == "login") {
            app.login();
        }
        else if (command == "logout") {
            app.logout();
        }
        else if (command == "list_friends") {
            app.listFriends();
        }
        else if (command == "view_profile") {
            app.viewProfile();
        }
        else if (command == "check_destination") {
            app.checkDestination();
        }
        else if (command == "exit") {
            weHaveEnteredExit = true;
        }
        else {
            cout << "Unknown command " << command << endl;
        }
        cout << endl;
    }
    return 0;
}