#include <iostream>
#include "List.cpp"
using namespace std;


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