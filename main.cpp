#include <iostream>
using namespace std;

template <class Type>
class List {
private:
    int length;
    int max;
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
        cout << "List is full! Cannot insert item." << endl;
    }
    else {
        data[length++] = item;
        cout << "Item inserted succesfully." << endl;
    }
}
template <class Type>
void List<Type>::deleteItem(Type item) {
    if (length == 0) {
        cout << "List is empty!" << endl;
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
            cout << "Item deleted successfully." << endl;
        }
        else {
            cout << "Item not found." << endl;
        }
    }
}
template <class Type>
void List<Type>::printList() const {
    for (unsigned int i = 0; i < length; i++) {
        cout << "Item " << i + 1 << ": " << data[i] << endl;
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


int main() {

    List<int> l(5);
    cout << "Length = " << l.getLength() << endl;
    cout << l.isEmpty() << endl;
    cout << l.isFull() << endl;
    l.insertItem(10);
    l.insertItem(2);
    l.insertItem(50);
    cout << l.searchItem(2) << endl;
    l.printList();
    l.deleteItem(100);
    l.deleteItem(10);

    return 0;
}