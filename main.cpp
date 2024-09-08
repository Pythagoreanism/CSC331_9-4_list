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
    List(const List<Type> &) // Copy constructor
    const List& operator=(const List<Type> &) // Operator overload

};

int main() {


    return 0;
}