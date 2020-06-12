#ifndef USER_H
#define USER_H
#include<iostream>
#include"String.h"
#include"Trip.h"
#include"Vector.h"
using std::cout;
using std::endl;

class User{
    String username;
    String password;
    String email;

    Vector<Trip> trips;
    Vector<String> friends;
    Vector<String> invitations;

public:
    User(){
        username = "";
        password = "";
        email = "";
        trips = Vector<Trip>();
        friends = Vector<String>();
        invitations = Vector<String>();
    }

    User(const String& _username, const String& _password, const String& _email){
        username = _username;
        password = _password;
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

    bool checkUserData(const String& usernameOrEmail, const String& _password) const {
        if(usernameOrEmail == username || usernameOrEmail == email){
            return password == _password;
        }
        return false;        
    }

    const Trip* getTrip(const String& destination) const{
        for(int i = 0; i < trips.getNumberOfElements(); i++){
            if(trips[i].getDestination() == destination){
                return &(trips[i]);
            }
        }
        return nullptr;
    }

    Vector<Trip> getAllTrips() const{
        return trips;
    } 

    String getUsername() const{
        return username;
    }

    
    String getEmail() const{
        return email;
    }

    String getPassword() const{
        return password;
    }
    
    void setPassword(const String& _password){
        password = _password;
    }

    void printFriendsList() const{
        for(int i = 0; i < friends.getNumberOfElements(); i++){
            cout << friends[i] << endl;
        }
    }

    void printTrips() const{
        for(int i = 0; i < trips.getNumberOfElements(); i++){
            trips[i].printTripInfo();
            cout << endl;
        }
    }
};
#endif