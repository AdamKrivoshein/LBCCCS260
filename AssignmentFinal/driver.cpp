#include <iostream>
#include "graph.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Graph myGraph;

    for (int i = 0; i < 10; i++) {
        myGraph.addVertex();
    }

    myGraph.addEdge(3, 1, 1);
    myGraph.addEdge(1, 3, 1);
    myGraph.addEdge(3, 8, 7);
    myGraph.addEdge(9, 2, 3);

    myGraph.displayMatrix();

    return 0;
}