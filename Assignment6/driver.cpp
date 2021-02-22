#include <iostream>
#include "binarysearchtree.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    BinarySearchTree tree;

    //Adding to empty tree, then removing the root
    tree.add(50);
    cout << "Tree pre-order with 50 added: " << endl;
    tree.printTree();
    tree.remove(50);
    cout << "Tree pre-order with 50 removed: " << endl;
    tree.printTree();

    //Adding 3 balanced nodes to the tree, then removing
    tree.add(60);
    tree.add(90);
    tree.add(30);
    cout << "Tree pre-order with 60, 90, 30 added: " << endl;
    tree.printTree();
    tree.remove(30);
    cout << "Tree pre-order with 30 removed: " << endl;
    tree.printTree();
    tree.remove(60);
    cout << "Tree pre-order with 60 removed: " << endl;
    tree.printTree();
    tree.remove(90);
    cout << "Tree pre-order with 90 removed: " << endl;
    tree.printTree();

    //Adding a whole bunch of random numbers and doing random removals
    tree.add(99);
    tree.add(34);
    tree.add(314);
    tree.add(230);
    tree.add(16);
    tree.add(82);
    tree.add(912);
    tree.add(65);
    tree.add(7);
    cout << "Tree pre-order with various numbers: " << endl;
    tree.printTree();
    tree.remove(99);
    tree.remove(16);
    tree.remove(314);
    tree.remove(912);
    cout << "Tree pre-order with 99, 16, 314, 912 removed: " << endl;
    tree.printTree();

    return 0;
}