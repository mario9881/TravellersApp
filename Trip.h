#ifndef TRIP_H
#define TRIP_H
#include<iostream>
#include"String.h"
#include"Vector.h"
using std::cout;
using std::endl;

class Trip{
    String destination;
    String startDate;
    String endDate;
    int grade;
    String comment;
    Vector<String> photos;

public:

    Trip(){
        destination = "";
        startDate = "";
        endDate = "";
        grade = 0;
        comment = "";
        photos = Vector<String>();
    }

    Trip(
        const String& _destination,
        const String& _startDate,
        const String& _endDate,
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
};

#endif