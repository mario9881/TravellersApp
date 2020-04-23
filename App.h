#ifndef APP_H
#define APP_H
#include<iostream>
#include"String.h"
#include"Trip.h"
#include"User.h"
#include"Vector.h"
using std::cin;
using std::cout;
using std::endl;

class App{
   Vector<User> users;
   User* loggedUser;

public:

    App(){
        users = Vector<User>();
        loggedUser = nullptr;
    }

    void createAccount(){
        String username;
        String password;
        String email;

        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        cout << "E-mail: ";
        cin >> email;

        // TODO: Check if user exists

        User newUser(username, password, email);
        users.addElement(newUser);
    }

    void addTrip(){

    }

    void invite(){

    }

    void accept(){

    }
    
    void login(){
        String usernameOrEmail;
        String password;

        cout << "Username or email: ";
        cin >> usernameOrEmail;

        cout << "Password: ";
        cin >> password;

        for(int i = 0; i < users.getNumberOfElements(); i++){
            if(users[i].checkUserData(usernameOrEmail, password)){
                loggedUser = &users[i];
                return;
            }
        }

        cout << "Incorrect username, email or password"<<endl;
    }

    void logout(){

    }

    void listFriends(){

    }

    void viewProfile(){

    }

    void checkDestination(){

    }


};

#endif