#ifndef APP_H
#define APP_H
#include<iostream>
#include<set>
#include<fstream>
#include"String.h"
#include"Trip.h"
#include"User.h"
#include"Vector.h"
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::set;

class App{
   Vector<User> users;
   User* loggedUser;
   set<String> destinations;

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
        if(loggedUser == nullptr){
            cout << "You must be logged in order to add trip!" << endl;
            return;
        }

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
        cin.ignore();
        readTillEndOfLine(comment, cin);

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

        if(!destinations.count(destination)){
            destinations.insert(destination);
        }
    }

    void invite(){
        if(loggedUser == nullptr){
            cout << "You must be logged in order to invite friends!" << endl;
            return;
        }

        String username;
        cin >> username;

        for(int i = 0; i < users.getNumberOfElements(); i++) {
            if(users[i].getUsername() == username) {
                loggedUser->sendInvitationTo(&users[i]);
            }
        }
    }

    void accept(){
        if(loggedUser == nullptr){
            cout << "You must be logged in order to accept request!" << endl;
            return;
        }
        String username;
        cin >> username;

        loggedUser->acceptInvitationFrom(username);
    }
    
    void login(){
        if(loggedUser != nullptr){
            cout << "There is a logged user already" << endl;
            return;
        }
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
        if(loggedUser == nullptr){
            cout << "You must be logged in order to see the friends list!" << endl;
            return;
        }
        loggedUser->printFriendsList();
    }

    void viewProfile(){
        if(loggedUser == nullptr){
            cout << "You must be logged in order to view profile!" << endl;
            return;
        }
        loggedUser->printTrips();
    }

    void checkDestination(){
        if(loggedUser == nullptr){
            cout << "You must be logged in order to check destination!" << endl;
            return;
        }
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
 
    void listAllDestinations(){ 
        for(String dest : destinations) {
            cout << dest << endl;
        }
    }

    void setNewPassword(){
        if(loggedUser == nullptr){
            cout << "You must be logged in order to change password!" << endl;
            return;
        }

        String newPassword;
        cin >> newPassword;
        loggedUser->setPassword(newPassword);
    }

    void saveInFiles(){
        ofstream out("users.db");

        out << users.getNumberOfElements() << endl;

        for(int i = 0; i < users.getNumberOfElements(); i++) {
            out << users[i].getUsername() << " " << users[i].getPassword() << " " << users[i].getEmail() << endl;

            ofstream userOfstream((users[i].getUsername() + ".db").toCharArray());

            Vector<Trip> tripsOfUser = users[i].getAllTrips();
            
            userOfstream << tripsOfUser.getNumberOfElements() << endl;

            for(int j = 0; j < tripsOfUser.getNumberOfElements(); j++) {
                userOfstream << tripsOfUser[j].getDestination() << " " 
                    << tripsOfUser[j].getStartDate() << " "
                    << tripsOfUser[j].getEndDate() << " "
                    << tripsOfUser[j].getGrade() << endl
                    << tripsOfUser[j].getComment() << endl
                    << tripsOfUser[j].getPhotos().getNumberOfElements() << endl;

                for(int k = 0; k < tripsOfUser[j].getPhotos().getNumberOfElements(); k++){
                    userOfstream << tripsOfUser[j].getPhotos()[k] << endl;
                }   
            }
        }
    }

    void readFromFiles(){
        ifstream in("users.db");

        int numberOfUsers;

        in >> numberOfUsers;

        for(int i = 0; i < numberOfUsers; i++){
            String username, password, email;
            in >> username >> password >> email;

            User user(username, password, email);
            users.addElement(user);
        }

        for(int i = 0; i < users.getNumberOfElements(); i++) {
            ifstream userIfstream((users[i].getUsername() + ".db").toCharArray());
            int numberOfTrips;

            userIfstream >> numberOfTrips;

            for(int k = 0; k < numberOfTrips; k++){
                String destination;
                Date startDate;
                Date endDate;
                int grade;
                String comment;
                int numberOfPhotos;
                Vector<String> photos;

                userIfstream >> destination;
                userIfstream >> startDate;
                userIfstream >> endDate;

                String gradeAsString;
                userIfstream >> gradeAsString;
                grade = gradeAsString.toInteger();

                userIfstream.ignore();

                readTillEndOfLine(comment, userIfstream);

                String numberOfPhotosAsString;
                userIfstream >> numberOfPhotosAsString;
                numberOfPhotos = numberOfPhotosAsString.toInteger();

                String photo;
                for(int j = 0; j < numberOfPhotos; j++){
                    userIfstream >> photo;
                    photos.addElement(photo);
                }

                Trip trip(destination, startDate, endDate, grade, comment, photos);
                users[i].addTrip(trip);
            }
        }
    }
};

#endif