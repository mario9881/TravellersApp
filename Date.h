#ifndef DATE_H
#define DATE_H
#include"String.h"

class Date{
    int day;
    int month;
    int year;

public:
    Date(){
        day = 0;
        month = 0; 
        year = 0;
    }

    Date(int _day, int _month, int _year){
        day = _day;
        month = _month;
        year = _year;
    }

    Date(String iso){
        
    }

    String toISO() const {
        return String(year) + "-" + String(month) + "-" + String(day);
    }
};

#endif

