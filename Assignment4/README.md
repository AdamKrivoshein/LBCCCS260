# Assignment 4: Arbitrary List Operations
I've elected to go for a linked list over an array, as practice with pointers is always good,
and the idea of also having a pointer to the end of the linked list to halve lookup times is intriguing to me if I get to it.

## node.h
**val:** Stores the value at each node.

**next:** Pointer to the next node.

**prev:** Pointer to the previous node.

## linkedList.h
### add()
**Inputs:** value, position

**nextNode** = **front's** node.

For each **position**:

    **nextNode** = **nextNode's** **next** node.

ERROR: This design doesn't really work. If user picks end of list, then it goes into NULL, or if prevented, nextNode doesn't point to the next node.

### remove()
tbd
### get()
tbd

## driver.cpp
Basic user input loop to allow adding, removing, and getting from the linked list.