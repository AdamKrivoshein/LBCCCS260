#include <iostream>
#include "hashTable.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    hashTable table;

    cout << "Adding values to the table..." << endl;
    table.insert("1");
    //The next 4 insertions all collide with each other deliberately for testing.
    table.insert("230");
    table.insert("320");
    table.insert("023");
    table.insert("302");

    table.insert("456");
    table.insert("78910");
    table.insert("Adam");
    table.insert("Eve");

    cout << "Checking for values the table contains: " << endl;
    cout << table.contains("320") << endl;
    cout << table.contains("023") << endl;
    cout << table.contains("Adam") << endl;
    cout << "Checking for vlaues the table doesn't contain: " << endl;
    cout << table.contains("203") << endl;
    cout << table.contains("What is a pie?") << endl;
    cout << table.contains(":)") << endl;

    cout << "Print the entire table: " << endl;
    table.printTable();

    return 0;
}