#include <iostream>
#include "binarysearchtree.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    BinarySearchTree tree;

    tree.add(50);
    tree.add(20);
    tree.add(90);
    tree.add(40);
    tree.add(2);
    tree.add(99);
    tree.add(1002);
    tree.add(13);
    tree.add(67);

    tree.printTree();

    return 0;
}