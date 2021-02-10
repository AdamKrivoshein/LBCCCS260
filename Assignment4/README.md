# Assignment 4: Arbitrary List Operations
I've elected to go for a linked list over an array, as practice with pointers is always good and I'll need these concepts for future data structures.

## node.h
**val:** Stores the value at each node.

**next:** Pointer to the next node.

## linkedList.h
### add()
**Inputs:** value, position

If front is null:

Add new node at front, pointing to null

if index is 0:

Add node at front, pointing to the next node

Otherwise iterate through the list until before the desired index, and store that for the next step.

Create a new node, and point the current node towards it, and set the new node's pointer to the next node.

### remove()
**Inputs:** index

Assuming front isn't empty:

if index is 0:

Store the value at front, make front point to the next node, delete old front, and return the value.

Iterate through the list until the node before the one to be removed.

If the next node isn't null:

Store the next node and it's value, set the current node's next to the next node's next, delete the next node, and return the value.

### get()
**Inputs:** index

Iterate through the list until the desired index, then return the value of that node.

## driver.cpp
Sequence of function calls to test the data structure.