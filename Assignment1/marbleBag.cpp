#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;

int red = 0;
int green = 0;
int blue = 0;
int maxMarbles = 100;
int nMarbles = 0;

void updateStats() {
    nMarbles = red + green + blue;
}

bool isFull(int addition = 0) {
    if (nMarbles + addition <= maxMarbles) {
        return false;
    }
    return true;
}

void addMarble(int nMarblesAdding = 0, char color = 'r') {
    switch(color) {
        case 'r':
            red += nMarblesAdding;
            break;
        case 'g':
            green += nMarblesAdding;
            break;
        case 'b':
            blue += nMarblesAdding;
            break;
    }
}

void addPhase() {
    char decision = 'n';
    int nMarblesAdding = 0;
    char color = 'r';

    cout << "Would you like to add any marbles (y or n): ";
    cin >> decision;
    if (decision == 'y') {
        do {
            cout << "How many marbles: ";
            cin >> nMarblesAdding;
        } while (isFull(nMarblesAdding));
        cout << "Which color (r or g or b): ";
        cin >> color;
        addMarble(nMarblesAdding, color);
    }
    updateStats();
}

bool canRemove(int nMarblesRemoving) {
    if (nMarbles - nMarblesRemoving < 0) {
        return false;
    }
    return true;
}

void removeMarbles(int nMarblesRemoving = 0) {
    int redRemoves = 0;
    int greenRemoves = 0;
    int blueRemoves = 0;
    srand(time(0));
    int initColor = rand() % 3;
    int remainingToRemove = nMarblesRemoving;

    if (red > 0) {
        minus = 
    }

    //This makes the program freeze. Should consider giving up on actual randomness, and just pick a random color to remove from, and remove the remainder from the next, and so on.
    /*while (nMarblesRemoving > 1) {
        redRemoves = rand() % nMarblesRemoving + 1;
        if (redRemoves <= red) {
            red -= redRemoves;
            nMarblesRemoving -= redRemoves;
        }
        greenRemoves = rand() % nMarblesRemoving + 1;
        if (greenRemoves <= green) {
            green -= greenRemoves;
            nMarblesRemoving -= greenRemoves;
        }
        blueRemoves = rand() % nMarblesRemoving + 1;
        if (blueRemoves <= blue) {
            blue -= blueRemoves;
            nMarblesRemoving -= blueRemoves;
        }
    }*/

    /*for (int i = 0; i < nMarblesRemoving; i++) {
        bool marbleRemoved = false;
        do {
            srand(time(0));
            int randColor = rand() % 3;

            switch(randColor) {
                case 0:
                    if (red > 0) {
                        red--;
                        marbleRemoved = true;
                        break;
                    }
                case 1:
                    if (green > 0) {
                        green--;
                        marbleRemoved = true;
                        break;
                    }
                case 2:
                    if (blue > 0) {
                        blue--;
                        marbleRemoved = true;
                        break;
                    }
            }
        } while (marbleRemoved == false);
    }*/
}

void removePhase() {
    char decision = 'n';
    int nMarblesRemoving = 0;

    cout << "Would you like to remove any marbles (y or n): ";
    cin >> decision;
    if (decision == 'y') {
        do {
            cout << "How many marbles: ";
            cin >> nMarblesRemoving;
        } while (canRemove(nMarblesRemoving));
        removeMarbles(nMarblesRemoving);
    }
}

void displayBag() {
    cout << "\nTotal marbles: " << red + green + blue << "\n";
    cout << "Red: " << red << "\n";
    cout << "Green: " << green << "\n";
    cout << "Blue: " << blue << "\n\n";
}

int main(){
    char loop = 'n';
    cout << "\nCongradulations! Your new cutting edge marble bag can hold up to 100 marbles!\n";

    do {
        addPhase();
        displayBag();
        removePhase();
        displayBag();
        cout << "Would you like to continue (y or n): ";
        cin >> loop;
    } while (loop == 'y');

    cout << "\n";
    return 0;
}