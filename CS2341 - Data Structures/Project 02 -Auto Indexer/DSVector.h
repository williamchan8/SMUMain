//
// Created by William Chan on 2/29/20.
//

#ifndef INC_20S_PA02_AUTOINDEXER_DSVECTOR_H
#define INC_20S_PA02_AUTOINDEXER_DSVECTOR_H
//include needed headers and libraries and sets std to be automatically used
#include <iostream>




using namespace std;

//sets up a template for the class


template <class T>
//creates the header for the DSVector class
class DSVector
{
//declares the class methods
public:
    DSVector<T>();
    DSVector<T>(DSVector<T>&);
    ~DSVector<T>();
    DSVector& operator=(const DSVector<T>&);

    T at(int);
    int getLength();
    int getCapacity();
    void setCapacity(int);
    void doubleCapacity();
    void orderedAdd(T);
    void push_back(T );
    void insert(T , int);
    T pop_back();
    T remove(int);
    void display();
//declares the three variables
private:
    int length{};
    int capacity{};
    T * arr;
};

//creates a template to be used for the default constructor
template <class T>
DSVector<T>::DSVector(){
    length = 0;
    capacity = 10;
    arr = new T [capacity];
}
//creates a template for copy constructor
template<class T>
DSVector<T>::DSVector(DSVector<T>& source){
    length = source.getLength();
    arr = new T[source.capacity];
    for(int i = 0; i < length; i++){
        arr[i] = source.at(i);
    }
}


template <class T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& source){
	delete[] arr;
	arr = new T[source.length];
	length = source.length;
	for(int i = 0; i < length; i++){
		arr[i] = source.arr[i];
	}
	return *this;
}

//creates a template to be used for the destructor
template <class T>
DSVector<T>::~DSVector<T>(){
    delete[] arr;
}

//creates a template to be used for the method that accesses an element from the DSVector
template <class T>
T DSVector<T>::at(int index){
    return arr[index];
}

//creates a template to be used to access the length of the DSVector
template <class T>
int DSVector<T>::getLength(){
    return length;
}

//creates a template to be used to access the capacity of the DSVector
template <class T>
int DSVector<T>::getCapacity(){
    return capacity;
}

//creates a template to be used to set the capacity of the DSVector
template <class T>
void DSVector<T>::setCapacity(int tCapacity){
    capacity = tCapacity;
}

//creates a template to be used to double the capacity of the DSVector
template <class T>
void DSVector<T>::doubleCapacity(){
    capacity *= 2;
    T * temp = new T [capacity];

    for(int k = 0; k < length; k++){
        temp[k] = arr[k];
    }

    delete[] arr;
    arr = temp;
}

//creates a template to be used to add an element to the JVector in order
template <class T>
void DSVector<T>::orderedAdd(T element){
    for(int k = 0;k < length;k++){
        T temp = arr[k];
        if(!(element == temp)){
            if(element < temp){
                this->insert(element, k);
                return;
            }
        }
    }
    this->push_back(element);
}


//creates a template to be used to add an element at the back of the DSVector
template <class T>
void DSVector<T>::push_back(T element){
    if(length >= capacity)
        doubleCapacity();

    arr[length] = element;
    length++;
}

//creates a template to be used to remove the last element from the DSVector
template <class T>
T DSVector<T>::pop_back(){
    length--;
    T removed = arr[length];

    T * temp = new T[capacity];

    for(int k = 0; k < length-1; k++){
        temp[k] = arr[k];
    }

    delete arr;
    arr = new T [capacity];

    for(int k = 0; k < length-1; k++){
        arr[k] = temp[k];
    }

    return removed;
}

//creates a template to be used to insert an element into the DSVector at a specified index
template <class T>
void DSVector<T>::insert(T element, int index){
    if(length >= capacity)
        doubleCapacity();

    T * temp = new T [capacity];

    for(int k = 0;k < index; k++){
        temp[k] = arr[k];
    }

    temp[index] = element;

    for(int k = index + 1;k<=length;k++){
        temp[k] = arr[k-1];
    }

    delete[] arr;
    length += 1;
    arr = temp;
}

//creates a template to be used to remove an element from the DSVector at a specified index
template <class T>
T DSVector<T>::remove(int index){
    T returned = arr[index];
    T * temp = new T [length-1];

    for(int k = 0;k < index;k++){
        temp[k] = arr[k];
    }

    for(int k = index;k < length-1;k++){
        temp[k] = arr[k+1];
    }

    delete arr;
    length -= 1;
    arr = temp;

    return returned;
}

//creates a template to be used to display the DSVector
template <class T>
void DSVector<T>::display(){
    cout << "[";
    for(int k = 0; k < length-1; k++){
        cout << arr[k] << endl;
    }
    cout << arr[length-1] << "]" << endl;
}


#endif
