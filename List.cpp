#include "List.h"
#include <iostream>

template <class Type>
void List<Type>::setLength(int l) { length = l; }
template <class Type>
int List<Type>::getLength() const { return length; }
template <class Type>
void List<Type>::setMax(int m) { max = m; }
template <class Type>
int List<Type>::getMax() const { return max; }
template <class Type>
bool List<Type>::isFull() const { return length == max; }
template <class Type>
bool List<Type>::isEmpty() const { return length == 0; }
template <class Type>
void List<Type>::insertItem(Type item) {
    if (length == max) {
        std::cout << "List is full! Cannot insert item." << std::endl;
    }
    else {
        data[length++] = item;
        std::cout << "Item inserted succesfully." << std::endl;
    }
}
template <class Type>
void List<Type>::deleteItem(Type item) {
    if (length == 0) {
        std::cout << "List is empty!" << std::endl;
    }
    else {
        bool isFound = false;
        int i = 0;

        while (i < length && !isFound) {
            if (data[i] == item) {
                isFound = true;
            }
            else {
                i++;
            }
        }

        if (isFound) {
            data[i] = data[length - 1];
            length --;
            std::cout << "Item deleted successfully." << std::endl;
        }
        else {
            std::cout << "Item not found." << std::endl;
        }
    }
}
template <class Type>
void List<Type>::printList() const {
    for (unsigned int i = 0; i < length; i++) {
        std::cout << "Item " << i + 1 << ": " << data[i] << std::endl;
    }
}
template <class Type>
bool List<Type>::searchItem(Type item) const {
    for (unsigned int i = 0; i < length; i++) {
        if (data[i] == item) {
            return true;
        }
    }

    return false;
}

template <class Type>
List<Type>::List(int size) : length(0), max(size), data(new Type[max]) {}
template <class Type>
List<Type>::~List() { delete [] data; }
template <class Type>
List<Type>::List(const List<Type>& right) {
    length = right.length;
    max = right.max;
    data = new Type[max];
    for (unsigned int i = 0; i < length; i++) { // Copies array contents
        data[i] = right.data[i];
    }
}
template <class Type>
const List<Type>& List<Type>::operator=(const List<Type>& other) {
    
    if (this == &other) {
        return *this;
    }
    else {
        length = other.length;
        max = other.max;
        data = new Type[max];
        for (unsigned int i = 0; i < length; i++) { 
            data[i] = other.data[i];
        }
    }
    
    return *this;
}
