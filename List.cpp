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
/**
 * @brief Checks if the list's length reached the maximum value of the list
 * @return Boolean
 * @retval true If length is the same as max
 * @retval false If length is not the same as max
 */
template <class Type>
bool List<Type>::isFull() const { return length == max; }
/**
 * @brief Checks if the list's is empty
 * @return Boolean
 * @retval true If length is 0
 * @retval false If length is not 0
 */
template <class Type>
bool List<Type>::isEmpty() const { return length == 0; }
/**
 * @brief Inserts an item to the list
 * @details Checks if the list is full, if not then it will append the item
 * to the list
 * @param item The item to be inserted into the list
 * @return void
 */
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
/**
 * @brief Deletes an item of the list
 * @details This function deletes an item in a simple but technical way.
 * It searches for the item being passed and checks if the item is in the list.
 * If the item is in the list, it will then take the last item of the list, 
 * replace the item that is being "deleted", and decrements the length by 1.
 * @param item The item being "deleted"
 * @return void
 */
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
/**
 * @brief Prints the contents of the list
 * @return void
 */
template <class Type>
void List<Type>::printList() const {
    for (unsigned int i = 0; i < length; i++) {
        std::cout << "Item " << i + 1 << ": " << data[i] << std::endl;
    }
}
/**
 * @brief A function that searches an item of the list
 * @param item The value that's being searched for
 * @return Boolean
 * @retval true If the item is found
 * @retval false If the item is not found
 */
template <class Type>
bool List<Type>::searchItem(Type item) const {
    for (unsigned int i = 0; i < length; i++) {
        if (data[i] == item) {
            return true;
        }
    }

    return false;
}
/**
 * @brief Default constructor for List
 * @details Constructed using the intializer list for readable code
 * @param size The maximum size to initialize the list. By default size is 100
 */
template <class Type>
List<Type>::List(int size) : length(0), max(size), data(new Type[max]) {}
/**
 * @brief Destructor for List
 */
template <class Type>
List<Type>::~List() { delete [] data; }
/**
 * @brief Copy constructor for List
 * @param other This is the object being copied from
 */
template <class Type>
List<Type>::List(const List<Type>& other) {
    length = other.length;
    max = other.max;
    data = new Type[max];
    for (unsigned int i = 0; i < length; i++) { // Copies array contents
        data[i] = other.data[i];
    }
}
/**
 * @brief Operator overload for the = operator
 * @details The function first checks if the object being copied from isn't
 * the same object copying it, then it follows the same copying process as 
 * the copy constructor
 * @see List(const List<Type> & other)
 * @param right This is the object being copied from, its on the right
 * side of the = operator
 * @return An instance of the List class with the contents of the object being
 * assigned from
 */
template <class Type>
const List<Type>& List<Type>::operator=(const List<Type>& right) {
    if (this == &right) {
        return *this;
    }
    else {
        length = right.length;
        max = right.max;
        data = new Type[max];
        for (unsigned int i = 0; i < length; i++) { 
            data[i] = right.data[i];
        }
    }
    
    return *this;
}
