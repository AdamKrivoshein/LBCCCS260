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
    myList.add(4, 1);
    cout << myList.get(1) << endl;

    return 0;
}