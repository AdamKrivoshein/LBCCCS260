#include <iostream>
#include "graph.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Graph myGraph;

    for (int i = 0; i < 8; i++) {
        myGraph.addVertex();
    }

    //Perform a drawn graph test on this tomorrow.
    myGraph.addEdge(0, 1, 1);
    myGraph.addEdge(1, 3, 1);
    myGraph.addEdge(3, 4, 7);
    myGraph.addEdge(3, 5, 6);
    myGraph.addEdge(4, 7, 3);
    myGraph.addEdge(5, 6, 9);
    myGraph.addEdge(7, 6, 1);
    myGraph.addEdge(7, 2, 8);

    cout << "Shortest path 0 - 7: " << myGraph.shortestPath(0, 2) << endl;

    myGraph.displayMatrix();

    cout << INT_MAX << endl;

    return 0;
}