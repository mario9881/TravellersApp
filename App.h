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

        for(int i = 0; i < users.getNumberOfElements(); i++){
            if(users[i].getUsername() == username || users[i].getEmail() == email){
                cout << "Username or e-mail already taken" << endl;
                return;
            }
        }

        User newUser(username, password, email);
        users.addElement(newUser);
    }

    void addTrip(){
        String destination;
        Date startDate;
        Date endDate;
        int grade;
        String comment;
        Vector<String> photos;

        cout << "Destination: ";
        cin >> destination;
        cout << "Start date: ";
        cin >> startDate;
        cout << "End date: ";
        cin >> endDate;
        cout << "Grade: ";
        cin >> grade;
        cout << "Comment: ";
        cin >> comment;

        int numberOfPhotos;
        cout << "Number of photos: ";
        cin >> numberOfPhotos;

        String photoName;
        for(int i = 0 ; i < numberOfPhotos; i++){
            cin >> photoName;
            photos.addElement(photoName);
        }      

        Trip newTrip(destination, startDate, endDate, grade, comment, photos);
        loggedUser->addTrip(newTrip);
    }

    void invite(){
        String username;
        cin >> username;

        for(int i = 0; i < users.getNumberOfElements(); i++) {
            if(users[i].getUsername() == username) {
                loggedUser->sendInvitationTo(&users[i]);
            }
        }
    }

    void accept(){
        String username;
        cin >> username;

        loggedUser->acceptInvitationFrom(username);
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
        loggedUser = nullptr;
    }

    void listFriends(){
        loggedUser->printFriendsList();
    }

    void viewProfile(){
        loggedUser->printProfileInfo();
    }

    void checkDestination(){
        String destination;
        cin >> destination;

        int numberOfGrades = 0;
        int sum = 0;

        for(int i = 0; i < users.getNumberOfElements(); i++){
            const Trip* pointerToTrip = users[i].getTrip(destination);
            if(pointerToTrip != nullptr){
                cout << "Username: " << users[i].getUsername() << "; "
                     << "Grade: " << pointerToTrip->getGrade() << endl;
                numberOfGrades++;
                sum  += pointerToTrip->getGrade();
            }
        }
        cout << "Avarage grade: " << sum / numberOfGrades << endl;
    }


};

#endif