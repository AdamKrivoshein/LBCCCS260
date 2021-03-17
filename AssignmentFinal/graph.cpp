#include <iostream>
#include <string>
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Graph {
    private:
        //https://stackoverflow.com/questions/16001803/pointer-to-pointer-dynamic-two-dimensional-array
        int **edgeMatrix;
        int *nodeList;
        int matrixSize = 4;
        int graphSize = 0;

    public:
        Graph() {
            //Setting up the 2d array edgeMatrix
            edgeMatrix = new int*[matrixSize];

            for (int row = 0; row < matrixSize; row++) {
                edgeMatrix[row] = new int[matrixSize];
                //Initializing edgeMatrix values
                for (int col = 0; col < matrixSize; col++)
                    edgeMatrix[row][col] = INT_MAX;
            }

            //Setting up the nodeList
            nodeList = new int[matrixSize];
        }

        void addVertex() {
            if (graphSize < matrixSize) {
                nodeList[graphSize] = graphSize;
                graphSize++;
            }
            else {
                expandMatrix();
                nodeList[graphSize] = graphSize;
                graphSize++;
            }
        }

        void addEdge(int source, int destination, int length) {
            if (source < graphSize && destination < graphSize)
                edgeMatrix[source][destination] = length;
        }

        void expandMatrix() {
            //Initializing new edgeMatrix
            int **newMatrix = new int*[matrixSize * 2];

            for (int row = 0; row < (matrixSize * 2); row++) {
                newMatrix[row] = new int[matrixSize * 2];
                //Initializing edgeMatrix values
                for (int col = 0; col < (matrixSize * 2); col++)
                    newMatrix[row][col] = INT_MAX;
            }

            //Transfering edgeMatrix data
            for (int row = 0; row < matrixSize; row++) {
                for (int col = 0; col < matrixSize; col++)
                    newMatrix[row][col] = edgeMatrix[row][col];
            }

            //Freeing old edgeMatrix memory
            for (int row = 0; row < matrixSize; row++)
                free(edgeMatrix[row]);
            free(edgeMatrix);

            //Transfering data
            edgeMatrix = newMatrix;
            matrixSize = matrixSize * 2;

            //Initializing new nodeList
            int *newList = new int[matrixSize * 2];

            //Transfering nodeList data
            for (int i = 0; i < matrixSize; i++)
                newList[i] = nodeList[i];

            free(nodeList);

            nodeList = newList;
        }

        int shortestPath(int source, int destination) {
            //Setting up shortestPath 2d array to store each node via index, distance from source, and parent
            int **shortestPaths;
            shortestPaths = new int*[graphSize];
            for (int i = 0; i < graphSize; i++) {
                shortestPaths[i] = new int[2];
                shortestPaths[i][0] = INT_MAX;
                shortestPaths[i][1] = INT_MAX;
            }
            shortestPaths[source][0] = 0;

            //Ensuring inputs are within the graph bounds
            if (source >= 0 && source < graphSize && destination >= 0 && destination < graphSize) {
                //Initializing nextNodes queue and list of visited nodes.
                Queue<int> nextNodes;
                int *visitedNodes = new int[graphSize];
                for (int i = 0; i < graphSize; i++)
                    visitedNodes[i] = 0;

                //Main algorithm
                nextNodes.enqueue(source);
                while (!nextNodes.isEmpty()) {
                    int currentNode = nextNodes.dequeue();
                    for (int col = 0; col < graphSize; col++) {
                        //Ensuring the node is actually connected and hasn't already been visited
                        if (edgeMatrix[currentNode][col] != INT_MAX && visitedNodes[currentNode] == 0) {
                            nextNodes.enqueue(col);
                            if (shortestPaths[currentNode][0] + edgeMatrix[currentNode][col] < shortestPaths[col][0]) {
                                shortestPaths[col][0] = shortestPaths[currentNode][0] + edgeMatrix[currentNode][col];
                                shortestPaths[col][1] = currentNode;
                            }
                        }
                    }
                    visitedNodes[currentNode] = 1;
                }
            }
            //Should consider also printing out the path taken as proof.
            //IMPORTANT: Also need to free datastructures here
            //Should also make sure this works when the graph is out of order
            return shortestPaths[destination][0];
        }

        Graph minSpanTree() {
            Graph minGraph;
            int cheapestEdge[3];
            bool finished = false;

            //while (!finished) {
            //    for ()
            //}
        }

        void displayMatrix() {
            cout << endl;
            for (int row = 0; row < matrixSize; row++) {
                for (int col = 0; col < matrixSize; col++) {
                    //For readiblity purposes "infinity" is replaced with 0
                    if (edgeMatrix[row][col] == INT_MAX)
                        cout << " 0";
                    else
                        cout << " " << edgeMatrix[row][col];
                }
                //Line break for each row
                cout << endl;
            }
            cout << endl;
        }

        void deleteGraph() {
            for (int row = 0; row < matrixSize; row++)
                free(edgeMatrix[row]);
            free(edgeMatrix);
        }

        //int getNodeList(int index)
};