#ifndef DATE_H
#define DATE_H
#include"String.h"
#include<fstream>
using std::istream;

class Date{
    String isoDate;

public:
    Date(){
        isoDate = "";
    }

    Date(int day, int month, int year){
        isoDate = String(year) + "-" + String(month) + "-" + String(day);
    }

    Date(String iso){
        isoDate = iso;
    }

    String toISO() const {
        return isoDate;
    }

};

istream& operator>>(istream& in, Date& date){
    String dateString;
    in >> dateString;

    date = Date(dateString);
    return in;
}

#endif

