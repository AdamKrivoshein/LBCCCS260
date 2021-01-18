# Assignment 2
Designing, but not coding, a queue and linked list for CS260 Data Structures are LBCC.

## Queue Design
### 1. Functions
// Probably just use an array, but check to see.
**push()**: Takes a value, increments **back**, and assigns the value to **back**.
**pop()**: Stores the value at **front**. Calls **shiftQueue()**. Returns the stored value from old **front**.
**shiftQueue()**: Iterates through the queue starting at **front**, assigning the value from the next index to the current index.
When **back** is reached, delete the value, and decrement **back**.
**printQueue()**: Iterates throughthe queue starting at **front**, printing the value at each index.
### 2. Values
**front**: Pointer to the front of the queue.
**back**: Pointer to the back of the queue.

## Linked List Design
### 1. Functions
1
2
3
### 2. Values
**linkHead**: Pointer to the first node in the linked list.
2
3