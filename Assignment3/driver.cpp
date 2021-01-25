#include <iostream>
#include "queue.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Queue<int> myQueue;

    char keepRunning = 'y';
    int input;
    char decision;

    while (keepRunning == 'y') {
        cout << "Would you like to add to the queue (y / n): ";
        cin >> decision;
        if (decision == 'y') {
            cout << "What value would you like to add to the queue: ";
            cin >> input;
            if (input != 'n')
                myQueue.enqueue(input);
        }
        cout << "Would you like to remove from the queue (y / n): ";
        cin >> decision;
        if (decision == 'y')
            cout << myQueue.dequeue() << endl;
        cout << "Would you like to continue (y / n): ";
        cin >> keepRunning;
    }

    return 0;
}