#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int marbles = 0;
int maxMarbles = 100;

void displayBag() {
    cout << endl << "There are " << marbles << " marbles in your bag." << endl << endl;
}

void addMarbles() {
    int numMarbles = 0;

    do {
        cout << "How many marbles would you like to add: ";
        cin >> numMarbles;
    } while (numMarbles < 0 || (marbles + numMarbles > maxMarbles));

    marbles += numMarbles;
}

void removeMarbles() {
    int numMarbles = 0;

    do {
        cout << "How many marbles would you like to remove: ";
        cin >> numMarbles;
    } while (numMarbles < 0 || (marbles - numMarbles < 0));

    marbles -= numMarbles;
}

int main() {
    char stop = 'y';
    
    cout << endl << "Congratulations! Your cutting edge new marble bag can hold up to 100 marbles!" << endl << endl;

    while (stop == 'y') {
        addMarbles();
        removeMarbles();
        displayBag();
        cout << "Would you like to keep going (y / n): ";
        cin >> stop;
    }

    return 0;
}