# Assignment 6: Binary Search Tree

## Design Requirements
|#|Requirement|Test|
|-|-----------|----|
|1|**add():** Node insertions should autosort, with left nodes being smaller, and right nodes larger.|A display tree function will let us verify the insertion is in it's appropriate spot.|
|2|**remove():** Node removals should link child nodes to parent node if present.|A display tree function will let us verify the correct removal and linking of child nodes.|

## node.h
**val:** Stores the data

**left:** Stores the data

**right:** Stores the data

## binarySearchTree.h
**add():**

*Inputs: root (of the tree), val (The value to be added).*

*Outputs: None.*

    if currentNode DNE:
        currentNode = new node with val
    else if val <= currentNode:
        if leftNode exists:
            recurse with leftNode, val
        else:
            add leftNode with val
    else:
        if rightNode exists:
            recurse with rightNode, val
        else:
            add rightNode with val
    return

**remove():**

*Inputs: root (or recursive node), val (The value to be removed).*

*Outputs: None.*

    removeNode = call findNode() with root, val

    if removeNode exists:
        
    return

**findNode():**

*Inputs: root (or recursive node), val (The value to find).*

*Outputs: node*

    if currentNode exists:
        if val < currentNode's val:
            //NOTE: This needs to store the value of the recursion so it can be further returned.
            recurse with leftNode
        else if val > currentNode's val:
            recurse with rightNode
        else:
            return currentNode
    return null node

**findSmallest():**

*Inputs: node*

*Outputs: node*

    if leftNode exists:
        recurse with leftNode
    return 

**inOrder(node, val):**

*Inputs: root (or recursive node).*

*Outputs: none.*

    if currentNode exists:
        print currentNode val
        if leftNode exists:
            recurse with leftNode
        else if rightNode exists:
            recurse with rightNode
    return

## driver.cpp
Initializes and runs the binary search tree.