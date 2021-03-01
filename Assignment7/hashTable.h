#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class hashTable {
    private:
        int arraySize = 20;
        string tableArray[20];

    public:

        void insert(string val) {
            int i = hash(val);
            tableArray[i] = val;
        }

        int hash(string val) {
            //https://www.geeksforgeeks.org/range-based-loop-c/
            int sum = 0;
            for (auto c : val)
                sum += int(c);
            sum %= arraySize;

            return sum;
        }

        void contains() {

        }

        void printTable() {

        }
};