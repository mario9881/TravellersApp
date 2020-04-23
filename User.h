#ifndef USER_H
#define USER_H
#include<iostream>
#include"String.h"
#include"Trip.h"
#include"Vector.h"
using std::cout;
using std::endl;

// TODO: Really encode the password
String encode(const String& password) {
    return password;
}

class User{
    String username;
    String encodedPassword;
    String email;

    Vector<Trip> trips;
    Vector<String> friends;
    Vector<String> invitations;

public:
    User(){
        username = "";
        encodedPassword = "";
        email = "";
        trips = Vector<Trip>();
        friends = Vector<String>();
        invitations = Vector<String>();
    }

    User(const String& _username, const String& password, const String& _email){
        username = _username;
        encodedPassword = encode(password);
        email = _email;
        trips = Vector<Trip>();
        friends = Vector<String>();
        invitations = Vector<String>();
    }

    void addTrip(const Trip& trip){
        trips.addElement(trip);
    }

    void receiveInvitationFrom(String otherName) {
        invitations.addElement(otherName);
    }

    void sendInvitationTo(User* other){
        other->receiveInvitationFrom(this->username);
    }

    void acceptInvitationFrom(String otherName){
        friends.addElement(otherName);
        invitations.removeValue(otherName);
    }

    bool checkUserData(const String& usernameOrEmail, const String& password) const {
        if(usernameOrEmail == username || usernameOrEmail == email){
            return encode(password) == encodedPassword;
        }
        return false;        
    }

    String getUsername() const{
        return username;
    }

    /*
    String getEmail() const{
        return email;
    }
    */

    void printFriendsList() const{
        for(int i = 0; i < friends.getNumberOfElements(); i++){
            cout << friends[i] << endl;
        }
    }

    void printProfileInfo() const{
        
    }
};
#endif