#include <iostream>
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;

class Graph {
    private:
        //https://stackoverflow.com/questions/16001803/pointer-to-pointer-dynamic-two-dimensional-array
        int **matrix;
        int matrixSize = 4;
        int graphSize = 0;

    public:
        Graph() {
            //Setting up the 2d array matrix
            matrix = new int*[matrixSize];

            for (int row = 0; row < matrixSize; row++) {
                matrix[row] = new int[matrixSize];
                //Initializing matrix values
                for (int col = 0; col < matrixSize; col++)
                    matrix[row][col] = 2147482647;
            }
        }

        void addVertex() {
            if (graphSize < matrixSize)
                graphSize++;
            else {
                expandMatrix();
                graphSize++;
            }
        }

        void addEdge(int source, int destination, int length) {
            if (source < graphSize && destination < graphSize)
                matrix[source][destination] = length;
        }

        void expandMatrix() {
            //Initializing new matrix
            int **newMatrix = new int*[matrixSize * 2];

            for (int row = 0; row < (matrixSize * 2); row++) {
                newMatrix[row] = new int[matrixSize * 2];
                //Initializing matrix values
                for (int col = 0; col < (matrixSize * 2); col++)
                    newMatrix[row][col] = 2147482647;
            }

            //Transfering matrix data
            for (int row = 0; row < matrixSize; row++) {
                for (int col = 0; col < matrixSize; col++)
                    newMatrix[row][col] = matrix[row][col];
            }

            //Freeing old matrix memory
            for (int row = 0; row < matrixSize; row++)
                free(matrix[row]);
            free(matrix);

            //Transfering data
            matrix = newMatrix;
            matrixSize = matrixSize * 2;
        }

        int shortestPath(int source, int destination) {
            //Setting up shortestPath 2d array to store each node via index, distance from source, and parent
            int **shortestPaths;
            shortestPaths = new int*[graphSize];
            for (int i = 0; i < graphSize; i++) {
                shortestPaths[i] = new int[2];
                shortestPaths[i][0] = 2147482647;
                shortestPaths[i][1] = 2147482647;
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
                        if (matrix[currentNode][col] != 2147482647 && visitedNodes[currentNode] == 0) {
                            nextNodes.enqueue(col);
                            //Need to review this downward...
                            if (shortestPaths[currentNode][0] + matrix[currentNode][col] < shortestPaths[col][0]) {
                                shortestPaths[col][0] = shortestPaths[currentNode][0] + matrix[currentNode][col];
                                shortestPaths[col][1] = currentNode;
                            }
                        }
                    }
                    visitedNodes[currentNode] = 1;
                }
            }

            return shortestPaths[destination][0];
        }

        //For debug purposes
        void displayMatrix() {
            cout << endl;
            for (int row = 0; row < matrixSize; row++) {
                for (int col = 0; col < matrixSize; col++) {
                    //For readiblity purposes "infinity" is replaced with 0
                    if (matrix[row][col] == 2147482647)
                        cout << " 0";
                    else
                        cout << " " << matrix[row][col];
                }
                //Line break for each row
                cout << endl;
            }
            cout << endl;
        }

        void deleteGraph() {
            for (int row = 0; row < matrixSize; row++)
                free(matrix[row]);
            free(matrix);
        }
};