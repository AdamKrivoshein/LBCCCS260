#include <iostream>
#include <string>
#include "linkedList.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class hashTable {
    private:
        int arraySize = 20;
        linkedList<string> tableArray[20];

    public:

        void insert(string val) {
            int i = hash(val);
            tableArray[i].add(val, 0);
        }

        int hash(string val) {
            //https://www.geeksforgeeks.org/range-based-loop-c/
            int sum = 0;
            for (auto c : val)
                sum += int(c);
            sum %= arraySize;

            return sum;
        }

        bool contains(string val) {
            int i = hash(val);
            return tableArray[i].contains(val);
        }

        void printTable() {
            for (auto item : tableArray) {
                item.displayList();
            }
        }
};