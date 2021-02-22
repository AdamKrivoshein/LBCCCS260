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

*Inputs: val (The value to be added).*

*Outputs: None.*

    if root = NULL:
        root = new node with val
    else:
        call addRecurse() with root, val

**addRecurse():**

*Inputs: node, val (The value to be added).*

*Outputs: None.*

    if val <= currentNode:
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

*Inputs: val (The value to be removed).*

*Outputs: None.*

    //Find parent of node to be removed
    nodeParent = call findNodeParent() with root, val

    if nodeParent exists:
        //Find and store node to be removed
        if nodeParent's leftNode exists:
            if nodeParent's leftNode = val:
                removeNode = nodeParent's leftNode
                side = 'l'
        else if nodeParent's rightNode exists:
            if nodeParent's rightNode = val:
                removeNode = nodeParent's rightNode
                side = 'r'

        //Removal Case: Node has no children
        if removeNode's leftNode & rightNode DNE:
            if side = 'l':
                nodeParent's left pointer = null
            else:
                nodeParent's right pointer = null
            free removeNode
            return

        //Removal Case: Node has children. Reorganizing is needed
        if removeNode's rightNode exists:
            replacementNode = call findSmallest with removeNode's rightNode
        else if removeNode's leftNode exists:
            replacementNode = call findLargest with removeNode's leftNode
            
        removeNode's val = replacementNode's val
        free replacementNode
        
    return

**findNodeParent():**

*Inputs: root (or recursive node), val (The value to find).*

*Outputs: node* (parent of target node. If the val is not found, then null is returned)

    if val < currentNode:
        if leftNode exists:
            if val != leftNode:
                return recurse with leftNode
            else:
                return currentNode
        return null
    else if val > currentNode:
        if rightNode exists:
            if val != rightNode:
                return recurse with rightNode
            else:
                return currentNode
        return null
    

    //Legacy return the exact node
    if currentNode exists:
        if val < currentNode's val:
            return recurse with leftNode
        else if val > currentNode's val:
            return recurse with rightNode
        else:
            return currentNode
    return null node

**findSmallest():**

*Inputs: node (The right node of a node to be removed)*

*Outputs: node*

    if leftNode's leftNode exists:
        return recurse with leftNode
    else:
        tempNode = leftNode
        pointer to leftNode = null
        return tempNode

**findLargest():**

*Inputs: node (The left node of a node to be removed)*

*Outputs: node*

    if rightNode's rightNode exists:
        return recurse with rightNode
    else:
        tempNode = rightNode
        pointer to rightNode = null
        return tempNode

**printTree():**

*Inputs: None.*

*Outputs: None (prints tree).*

    calls inOrder() with root

**inOrder():**

*Inputs: root (or recursive node).*

*Outputs: None.*

    if currentNode exists:
        print currentNode val
        if leftNode exists:
            recurse with leftNode
        if rightNode exists:
            recurse with rightNode
    return

## driver.cpp
Initializes and runs the binary search tree.