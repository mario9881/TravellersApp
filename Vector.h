#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {              
    T* arr;
    int numberOfElements;

public:
    bool hasElement(T element) const {
        for (int i = 0; i < numberOfElements; i++) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }

    Vector() {
        numberOfElements = 0;
        arr = nullptr;
    }

    Vector(const Vector<T>& other) {
        numberOfElements = other.numberOfElements;
        arr = new T[numberOfElements];

        for (int i = 0; i < numberOfElements; i++) {
            arr[i] = other.arr[i];
        }
    }

    Vector& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] arr;

            numberOfElements = other.numberOfElements;
            arr = new T[numberOfElements];

            for (int i = 0; i < numberOfElements; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~Vector() {
        delete[] arr;
    }

    void addElement(T element) {
        T* newArr = new T[numberOfElements+1];

        for(int i = 0; i < numberOfElements; i++){
            newArr[i] = arr[i];
        }

        newArr[numberOfElements] = element;         
        
        delete[] arr;
        arr = newArr;

        numberOfElements++;
    }

    int getNumberOfElements() const {
        return numberOfElements;
    }

    T& operator[](int i) {
        return arr[i];
    }

    const T& operator[](int i) const {
        return arr[i];
    }

    void removeAt(int i) {
        for (int k = i + 1; k < numberOfElements; k++) {
            arr[k - 1] = arr[k];
        }
        numberOfElements--;
    }

    void removeValue(T value) {
        for (int i = 0; i < numberOfElements; i++) {
            if (arr[i] == value) {
                removeAt(i);
                i--;
            }
        }
    }

    void removeDuplicates() {
        for (int i = 0; i < numberOfElements; i++) {
            for (int k = i + 1; k < numberOfElements; k++) {
                if (arr[i] == arr[k]) {
                    removeAt(k);
                    k--;
                }
            }
        }
    }
};

#endif