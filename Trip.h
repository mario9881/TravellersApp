#ifndef TRIP_H
#define TRIP_H
#include<iostream>
#include"String.h"
#include"Vector.h"
#include"Date.h"
using std::cout;
using std::endl;

class Trip{
    String destination;
    Date startDate;
    Date endDate;
    int grade;
    String comment;
    Vector<String> photos;

public:

    Trip(){
        destination = "";
        startDate = Date();
        endDate = Date();
        grade = 0;
        comment = "";
        photos = Vector<String>();
    }

    Trip(
        const String& _destination,
        const Date& _startDate,
        const Date& _endDate,
        int _grade,
        const String& _comment,
        const Vector<String>& _photos
    ) {
        destination = _destination;
        startDate = _startDate;
        endDate = _endDate;
        grade = _grade;
        comment = _comment;
        photos = _photos;
    }

    String getDestination() const{
        return destination;
    }

    Date getStartDate() const{
        return startDate;
    }

    Date getEndDate() const{
        return endDate;
    } 

    int getGrade() const{
        return grade;
    }

    String getComment() const{
        return comment;
    }

    Vector<String> getPhotos() const{
        return photos;
    }

    void printTripInfo() const{
        cout << "Destiantion: " << destination << endl 
             << "Start date: " << startDate << endl
             << "End date: " << endDate << endl
             << "Grade: " << grade << endl
             << "Comment: " << comment << endl
             << "Photos: " << endl;

        for(int i = 0; i < photos.getNumberOfElements(); i++){
            cout << photos[i] << endl;
        }
    }
};

#endif