# Assignment 6: Binary Search Tree

## Design Requirements
|#|Requirement|Test|
|-|-----------|----|
|1|**add():** Node insertions should autosort, with left nodes being smaller, and right nodes larger|A display tree function will let us verify the insertion is in it's appropriate spot|
|2|**remove():** TBD|TBD|

## node.h
**val:** Stores the data

**left:** Stores the data

**right:** Stores the data

## binarySearchTree.h
**add():**

*Inputs: val (The value to be added).*

*Outputs: None.*

    node = call traverse, passing root, val
    if node DNE:
        node = new node with val
    else if val <= node:
        node's left = new node with val
    else:
        node's right node = new node with val

**remove():**



**traverse(node, val):**

*Inputs: root (or recursive node), val (That you would like to find).*

*Outputs: the node with a matching value (for removal), or if there's no match, the appropriate node it would added under.*

    if currentNode DNE:
        return currentNode
    else if val <= currentNode:
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