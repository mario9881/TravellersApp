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
    Vector<User*> friends;
    Vector<User*> invitations;

public:
    User(){
        username = "";
        encodedPassword = "";
        email = "";
        trips = Vector<Trip>();
        friends = Vector<User*>();
        invitations = Vector<User*>();
    }

    User(const String& _username, const String& password, const String& _email){
        username = _username;
        encodedPassword = encode(password);
        email = _email;
        trips = Vector<Trip>();
        friends = Vector<User*>();
        invitations = Vector<User*>();
    }

    void addTrip(const Trip& trip){
        trips.addElement(trip);
    }

    void receiveInvitationFrom(User* other) {
        invitations.addElement(other);
    }

    void sendInvitationTo(User* other){
        other->receiveInvitationFrom(this);
    }

    void acceptInvitationFrom(User* other){
        friends.addElement(other);
        invitations.removeValue(other);
    }

    bool checkUserData(const String& usernameOrEmail, const String& password) const {
        if(usernameOrEmail == username || usernameOrEmail == email){
            return encode(password) == encodedPassword;
        }
        return false;        
    }

    /*
    String getusername() const{
        return username;
    }

    String getEmail() const{
        return email;
    }
    */
};
#endif