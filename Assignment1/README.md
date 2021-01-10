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
The function addMarble() will handle all aspects of adding marbles.

!-- WHAT IF THEY WANT TO ADD MORE THAN ONE, AND DIFFERENT COLORS, OR RANDOM?

It will first ask if you user would like to add a marble, and if not it returns.
Then it will ask which color, and will increment the associated marble color variable, red, green, or blue.

## 3. Removing Marbles
The function removeMarble() will handle all aspects of removing marbles.

## 4. Verification Functions