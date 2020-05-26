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

    int getGrade() const{
        return grade;
    }
};

#endif