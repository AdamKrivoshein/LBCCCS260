#include <iostream>
#include <string>
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Graph {
    public:
        int **edgeMatrix;
        int *nodeList;
        int matrixSize = 4;
        int graphSize = 0;

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

        //Only to be used on minGraphs
        void addVertex(int node) {
            if (graphSize < matrixSize) {
                nodeList[graphSize] = node; //nodeList[node] = graphSize;
                graphSize++;
            }
            else {
                expandMatrix();
                nodeList[graphSize] = node;
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

        Graph minSpanTree(int source) {
            Graph minGraph;
            int cheapestEdge[3];
            bool finished = false;

            cheapestEdge[0] = 0;
            cheapestEdge[1] = INT_MAX;
            cheapestEdge[2] = 0;

            minGraph.addVertex(source);

            while (!finished) {
                //cout << "Entering while loop..." << endl;
                cout << "minGraph.graphSize = " << minGraph.graphSize << endl;
                for (int i = 0; i < minGraph.graphSize; i++) {
                    //cout << "minGraph loop..." << endl;
                    int minNode = minGraph.nodeList[i];
                    for (int col = 0; col < graphSize; col++) {
                        //cout << "matrix loop... @ edgeMatrix[" << minNode << "][" << col << "]" << endl;
                        if (edgeMatrix[minNode][col] < cheapestEdge[1] && !minGraph.isInNodeList(col)) {
                            cheapestEdge[0] = minNode;
                            cheapestEdge[1] = edgeMatrix[minNode][col];
                            cheapestEdge[2] = col;
                            cout << "Found cheap edge: " << cheapestEdge[0] << " " << cheapestEdge[1] << " " << cheapestEdge[2] << endl;
                            
                        }
                    }
                }
                if (cheapestEdge[1] != INT_MAX) {
                    //It looks like it's actually finding and attempting to add the correct vertices and edges,
                    //but somehow is failing to add most of them.
                    minGraph.addVertex(cheapestEdge[2]);
                    minGraph.addEdge(cheapestEdge[0], cheapestEdge[2], cheapestEdge[1]);
                    cout << "!--- Added cheap edge: " << cheapestEdge[0] << " " << cheapestEdge[1] << " " << cheapestEdge[2] << endl;
                }
                else
                    finished = true;
                cheapestEdge[0] = 0;
                cheapestEdge[1] = INT_MAX;
                cheapestEdge[2] = 0;
            }

            return minGraph;
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

        bool isInNodeList(int val) {
            cout << "Entering isInNodList()" << endl;
            for (int i = 0; i < graphSize; i++) {
                //cout << "nodeList[" << i << "] = " << nodeList[i] << endl;
                if (nodeList[i] == val)
                    return true;
            }
            return false;
        }
};