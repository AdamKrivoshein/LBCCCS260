# Assignment 3: Linked Queue

## node.h
Struct with a value variable, and a pointer to the next node.

## queue.h
A class
### Variables
Pointer node front

Pointer node back
### Functions
#### enqueue()
Assigns a new node to back, assigning the appropriate value, and next to null.
If a previous back node exists, sets the previous back to point to the new back.
#### dequeue()
Saves the value at front for returning. Sets front to the next node pointed to, unless there is no next node, in which case front and back are set to null.

#### displayQueue()
Internal function only meant for verifying other functions.

Outputs the first value if it's there, then iterates through each next pointer, printing each value, until the next pointer is null.