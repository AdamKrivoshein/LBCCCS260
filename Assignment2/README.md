# Assignment 2
Designing, but not coding, a queue and linked list for CS260 Data Structures are LBCC.

## Queue Design

### 1. Functions
**push()**: Takes a value, increments **back**, and assigns the value to the index **back** of **queue**.

**pop()**: Stores the value of index 0 of **queue**. Calls **shiftQueue()**. Returns the stored value.

**shiftQueue()**: Iterates through the **queue**, assigning the value from the next index to the current index.
When **back** is reached, delete the value, and decrement **back**.

**printQueue()**: Iterates through **queue**, printing the value at each index.

### 2. Values
**queue**: Array of values.

**back**: Stores the size of the queue, -1, so it can be used as an index to access the last element.

**limit**: Size limit of the array that the queue is stored inside of.

## Linked List Design

### 1. Functions
**insertAt()**: Starting at **head**, iterates through each node's **next** pointer, decrementing the supplied index each time, until the supplied index equals 0
and we've reached the node before the target node, or the next node does not exist. 

If there is a next node, create a new node, set it's **next** equal to the next node, and set the
pre existing node's **next** equal to the new node.

Otherwise, create a new node, set it's **next** equal to NULL, and set the pre existing node's **next** equal to the new node.

**removeAt()**: Starting at **head**, iterate through each node's **next** pointer, decrementing the supplied index each time, until the supplied index equals 0
and we've reached the node before the target node, or the next node does not exist.

If there is a next node, save the pointer to it, and set the current node's **next** equal to the next node's **next** if it exists.
Then set the next node's values equal to NULL.

### 2. Values
**Node** class: A small node class with a **value** variable, and **next** variable pointing to the next node.

**head**: Pointer to the first node in the linked list.