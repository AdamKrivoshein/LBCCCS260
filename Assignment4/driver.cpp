#include <iostream>
#include "linkedList.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    linkedList<int> myList;

    myList.add(1, 0);
    myList.add(2, 0);
    myList.add(3, 2);
    cout << myList.remove(0) << endl;

    return 0;
}