#ifndef LIST_H
#define LIST_H

/**
 * @class List
 * @brief A class that simulates a list data structure
 * @details The List is a template class that has several functions to match that of a list such as 
 * adding, removing, checking if its full, empty.
 */
template <class Type>
class List {
private:
    /**
     * @var length
     * @brief The current length of the list
     */
    int length;
    /**
     * @var max
     * @brief The maximum value that the length can reach.
     */
    int max;
    /**
     * @var *data
     * @brief A pointer that is assigned to an array at runtime
     */
    Type* data;

public:
    void setLength(int l);
    int getLength() const;
    void setMax(int m);
    int getMax() const;
    bool isFull() const;
    bool isEmpty() const;
    void insertItem(Type);
    void deleteItem(Type);
    void printList() const;
    bool searchItem(Type) const;

    List(int = 100); // Default constructor
    ~List(); // Destructor
    List(const List<Type> &); // Copy constructor
    const List& operator=(const List<Type> &); // Operator overload

};


#endif