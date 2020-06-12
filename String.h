#ifndef STRING_H
#define STRING_H
#include<cstring>
#include<fstream>
using std::istream;
using std::ostream;

class String {
    char* pointer;

public:
    String(){
        pointer = new char[1];
        pointer[0] = '\0';
    }

    String(const char* _pointer) {
        pointer = new char[strlen(_pointer) + 1];
        
        int i = 0;
        for (i = 0; _pointer[i] != '\0'; i++) {
            pointer[i] = _pointer[i];
        }
        pointer[i] = '\0';
    }

    // TODO: Test
    String(int integer) {
        char temp[16];
        int length = 0;
        int digit;

        while(integer > 0) {
            digit = integer % 10;
            temp[length] = '0' + digit;  // Така превръщаме 2 в '2', 3 в '3' и т.н.
            length++;
            integer /= 10;
        }

        // 0 1 2 3 4 5     length = 6
        // 0 1 2 3 4 5 6   length = 7
        // И в двата случая трябва да разменим символите с индекси < lenght/2 = 3
        // със символите в края на temp
        for(int i = 0; i < length/2; i++) {
            int helper = temp[i];
            temp[i] = temp[length-1-i];
            temp[length-1-i] = helper;
        }

        pointer = new char[length + 1];
        int i = 0;
        for (i = 0; temp[i] != '\0'; i++) {
            pointer[i] = temp[i];
        }
        pointer[i] = '\0';
    }

    String(const String& other) {
        pointer = new char[strlen(other.pointer) + 1];
        
        int i = 0;
        for (i = 0; other.pointer[i] != '\0'; i++) {
            pointer[i] = other.pointer[i];
        }
        pointer[i] = '\0';
    }

    String& operator=(const String& other) {
        if(this != &other){
            delete[] pointer;

            pointer = new char[strlen(other.pointer) + 1];
        
            int i = 0;
            for (i = 0; other.pointer[i] != '\0'; i++) {
                pointer[i] = other.pointer[i];
            }
            pointer[i] = '\0';
        }
        return *this;
    }

    ~String() {
        delete[] pointer;
    }

    // this е указател към първия стринг
    // other е референция към втория стринг
    String operator+(const String& other) const {
        String newString;

        int thisSize = this->size();
        
        int otherSize = other.size();

        int newStringSize = thisSize + otherSize;

        newString.pointer = new char[newStringSize + 1];

        for(int i = 0; this->pointer[i] != '\0'; i++){
            newString.pointer[i] = this->pointer[i];
        }

        for(int i = 0; other.pointer[i] != '\0'; i++){
            newString.pointer[thisSize + i] = other.pointer[i];
        }
        newString.pointer[newStringSize] = '\0';

        return newString;
    }

    bool operator==(const String& other) const {
        int length = strlen(pointer);
       
        if (length != strlen(other.pointer)) {
            return false;
        }

        for (int i = 0; i < length; i++) {
            if (pointer[i] != other.pointer[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator<(const String& other) const{
        return strcmp(pointer, other.pointer) < 0;
    }

    char operator[](int i) const {
        return pointer[i];
    }

    int size() const {
        return strlen(pointer);
    }

    const char* toCharArray() const {
        return pointer;
    }

    bool isInteger() const{
        if (pointer == "-") {        
            return false;       
        }                      

        if (pointer[0] != '-' && (pointer[0] < '0' || '9' < pointer[0])) {
            return false;
        }

        int length = size();

        for (int i = 1; i < length; i++) {
            if (pointer[i] < '0' || '9' < pointer[i]) {
                return false;
            }
        }

        return true;
    }

    int toInteger() const{
        int result = 0;
        for(int i = 0; pointer[i] != '\0'; i++){
            result = result * 10 + (pointer[i] - '0');
        }
        return result;
    }
};

ostream& operator<< (ostream& out, const String& s) {
    for (int i = 0; i < s.size(); i++) {
        out << s[i];
    }
    return out;
}

bool isWhiteSpace(char symbol) {
    return symbol == ' ' || symbol == '\n' || symbol == '\t';
}

istream& operator>> (istream& in, String& s) {
    s = "";
    // while (isWhiteSpace(in.peek())) {   // Прескачаме всички интервали, нови редове и табулации ПРЕДИ стринга 
    //     in.ignore();                    
    // }

    // char* helper = new char[8];
    // int helperLength = 0;
    // int capacity = 8;

    // while (!isWhiteSpace(in.peek())) {  // Започнали сме да четем стринга. Продължаваме, докато (отново) не
    //     char newSymbol;                 // видим интервал, нов ред или табулация
    //     in >> newSymbol;
        
    //     if(helperLength == capacity - 1) {
    //         char* newArr = new char[capacity * 2];
    //         for(int k = 0; k < helperLength; k++) {
    //             newArr[k] = helper[k];
    //         }
    //         delete[] helper;
    //         helper = newArr;
    //     }
    //     helper[helperLength] = newSymbol;
    //     helperLength++;
    // }
    // helper[helperLength] = '\0';

    char helper[200];
    in >> helper;

    s = String(helper);

    return in;
}

void readTillEndOfLine(String& s, istream& in){
    char arr[200];
    in.getline(arr, 200);
    s = String(arr);
}

#endif