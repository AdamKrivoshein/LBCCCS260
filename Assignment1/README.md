# CS 260 - Assignment 1
Designing a bag of marbles as simply as possible.

## 1. Marble Representation
Marbles will be represented primarily through 3 int variables: red, green, and blue.
```
int red = 0
int green = 0
int blue = 0
```
In addition to this there will be an int nMarbles variable to keep track of the total number of marbles by adding the three types together.
In combination with int maxMarbles variable, these will ensure that the bag is not overfilled.

## 2. Adding Marbles
addPhase() will ask the user:
1. If they would like to add a marble
2. How many marbles
3. Which color

addMarbles() will take in an int for how many marbles, and a character to symbolize which color, or random color to add.
The associated color will be incremented by the amount specified.

## 3. Removing Marbles
removePhase() will ask the user how many marbles they would like to remove.

removeMarbles() will take in an int for how many marbles to remove, and will randomly remove that many marbles.

## 4. Verification Functions
displayBag() will print the contents of the bag, broken down into total and individual colors