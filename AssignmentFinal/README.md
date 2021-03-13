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

**addEdge(source, destination):**

    graphMatrix at source, destination = 1

**expandMatrix():**

    for each matrix row:
        for each matrix column:

**shortestPath(source, destination):**

**minSpanTree():**