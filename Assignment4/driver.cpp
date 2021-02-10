#include <iostream>
#include "linkedList.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    linkedList<int> myList;
    myList.add(3, 0);
    myList.add(1, 0);
    myList.add(4, 2);
    myList.add(2, 1);
    cout << "Get function test:" << endl;
    cout << myList.get(0) << endl;
    cout << myList.get(1) << endl;
    cout << myList.get(2) << endl; 
    cout << myList.get(3) << endl;
    cout << myList.get(4) << endl;
    cout << "Remove and get function test:" << endl;
    cout << myList.get(0) << endl;
    cout << myList.remove(0) << endl;
    cout << myList.get(1) << endl;
    cout << myList.remove(1) << endl;
    cout << myList.get(20) << endl;
    cout << myList.remove(20) << endl;
    cout << myList.get(0) << endl;
    cout << myList.remove(0) << endl;

    return 0;
}