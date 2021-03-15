# Final Project: Graph

## Design Requirements

## graph.h

**matrix 2d array** = 16x16 integers

**graphSize** = 0

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

**minSpanTree():**

**displayMatrix():**

    For matrixSize row:
        for MatrixSize col:
            print matrix @ row, col
        print line break