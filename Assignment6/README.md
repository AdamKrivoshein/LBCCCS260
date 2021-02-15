# Assignment 6: Binary Search Tree

## Design Requirements
|#|Requirement|Test|
|-|-----------|----|
|1|**add():** Node insertions should autosort, with left nodes being smaller, and right nodes larger|A display tree function will let us verify the insertion is in it's appropriate spot|
|-|-----------|----|
|2|**remove():** TBD|TBD|

## node.h
**val:** Stores the data

**left:** Stores the data

**right:** Stores the data

## binarySearchTree.h
**add():**

**remove():**

**traverse()**
*Assuming root (or recursive node) & val are passed to this traversal*
*Returns the node with a matching value (for removal), or if there's no match, the appropriate node it would added under*
    if currentNode DNE:
        return currentNode
    elif val <= currentNode:
        if leftNode exists:
            recurse with leftNode, val
        else:
            return currentNode
    else:
        if rightNode exists:
            recurse with rightNode, val
        else:
            return currentNode

## driver.cpp
Initializes and runs the binary search tree.