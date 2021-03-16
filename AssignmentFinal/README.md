# Final Project: Graph

## Design Requirements

## graph.h

**matrix 2d array** = 16x16 integers

**graphSize** = 2147482647 ("infinity")

**addVertex():**

    if graphSize < matrixSize:
        size = size + 1
    else:
        expandMatrix()
        size = size + 1

Idea: Add addVertex(vertextName, destination) as an overflow function that also calls addEdge().

**addEdge(source, destination, val):**

    graphMatrix at source, destination = val

**expandMatrix():**

    Initialize temp matrix @ 2x matrixSize

    for each matrix row:
        for each matrix column:
            temp @ row, col = matrix @ row, col

    free matrix
    matrix = temp
    matrixSize = matrixSize * 2


**shortestPath(source, destination):**

    Initialize shortestPaths 2 x graphSize 2d array (First index is the node id, 0 is distance which is defaulted to 2147482647, 1 is parent)
    shortestPaths @ source, 0 (distance) = 0
    Initialize nextNodes queue
    Initialize visited array (values initiailized to 0)

    add source to nextNodes

    while nextNodes isn't empty:
        currentNode = pop from nextNodes
        for each graph column:
            if matrix @ currentNode, col != 2147482647 && visited @ currentNode = 0:
                add col to nextNodes
                if shortestPaths @ currentNode, 0 + matrix @ currentNode, col < shortestPaths @ col, 0:
                    shortestPaths @ col, 0 = shortestPaths @ currentNode, 0 + matrix @ currentNode, col
                    shortestPaths @ col, 1 = currentNode
        visited @ currentNode = 1

        return shortestPaths @ destination, 0

**minSpanTree(source):**

    Initialize minGraph graph
    Initialize cheapestEdge array (3 long, 0 being the source node, 1 being distance, 2 being the new node)
    finished = 0

    add source to minGraph

    while finished = 0
        //ISSUE: Would normally just use for row in minGraph.graphSize, but the nodes could be added out of order.
        //       For example: minSpan tree could contain 1, 3. 1, 2 would be searched, but not 3.
        //       Solution is probably a recursive search of the minTree.
        for minNode in minGraph //HOW???
            for col in graphSize
                if matrix @ minNode, col < cheapestEdge @ 1
                    cheapestEdge @ 0 = minNode
                    cheapestEdge @ 1 = matrix @ minNode, col
                    cheapestEdge @ 2 = col
        if cheapestEdge @ 1 != infinity:
            add cheapestEdge @ 2 to minGraph
        else:
            finished = 1
        cheapestEdge @ 0 = 0
        cheapestEdge @ 1 = infinity
        cheapestEdge @ 2 = 0

**displayMatrix():**

    For matrixSize row:
        for MatrixSize col:
            print matrix @ row, col
        print line break