#include <iostream>
#include "hashTable.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    hashTable table;

    table.insert("1");
    table.insert("230");
    table.insert("320");
    table.insert("023");
    table.insert("302");
    table.insert("456");
    table.insert("78910");
    table.insert("Adam");
    table.insert("Eve");

    cout << table.contains("320") << endl;
    cout << table.contains("023") << endl;
    cout << table.contains("203") << endl;


    table.printTable();

    return 0;
}