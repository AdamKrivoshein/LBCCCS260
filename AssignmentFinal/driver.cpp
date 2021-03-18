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

    myGraph.addEdge(0, 1, 1);
    myGraph.addEdge(1, 3, 1);
    myGraph.addEdge(3, 4, 7);
    myGraph.addEdge(3, 5, 6);
    myGraph.addEdge(4, 7, 3);
    myGraph.addEdge(5, 6, 9);
    myGraph.addEdge(6, 5, 5);
    myGraph.addEdge(7, 6, 1);
    myGraph.addEdge(7, 2, 8);

    cout << endl << "My graph is implemented via a matrix. Displayed are the directional connections and their distance." << endl << endl;

    cout << "Shortest path 0 - 2: " << myGraph.shortestPath(0, 2) << endl;
    cout << "Shortest path 3 - 6: " << myGraph.shortestPath(3, 6) << endl;

    myGraph.displayMatrix();

    Graph minGraph = myGraph.minSpanTree(0);

    cout << "Minimum Spanning Tree:" << endl;

    minGraph.displayMatrix();

    return 0;
}