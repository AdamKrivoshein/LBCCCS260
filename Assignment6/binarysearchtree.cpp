#include <iostream>
#include "node.h"

using std::cout;
using std::cin;
using std::endl;

class BinarySearchTree {
    private:
        Node<int>* root = nullptr;

    public:
        //Function: Adds a node to the tree with the value specified.
        //Inputs: int (value to be inserted)
        //Outputs: None
        void add(int val) {
            if (root == nullptr)
                root = new Node<int>(val, nullptr, nullptr);
            else
                addRecurse(root, val);
            return;
        }

        //Function: Recursively searches the tree for the appropriate spot to add the value specified.
        //Inputs: Node* (root initially, or recursive nodes), int (value to be inserted)
        //Outputs: None
        void addRecurse(Node<int>* node, int val) {
            if (val <= node->val)
                if (node->left != nullptr)
                    addRecurse(node->left, val);
                else
                    node->left = new Node<int>(val, nullptr, nullptr);
            else
                if (node->right != nullptr)
                    addRecurse(node->right, val);
                else
                    node->right = new Node<int>(val, nullptr, nullptr);
            return;
        }

        //Function: Begins the process of removing a node.
        //Inputs: int (value to be removed)
        //Outputs: None.
        void remove(int val) {
            //Node<int>* removeNode = findNode();
        }

        //Function: Finds and returns a node with a specified value.
        //Inputs: Node* (root or recursive node), int (value to be found)
        //Outputs: Node*
        /*Node<int>* findNode(Node<int>* node, int val) {
            
        }*/

        //Function: Finds & returns the largest node below the given node.
        //Inputs: Node* (The left node of a node to be removed)
        //Outputs: Node*.
        /*Node<int>* findLargest(Node<int>* node) {

        }*/

        //Function: Finds & returns the smallest node below the given node.
        //Inputs: Node* (The right node of a node to be removed)
        //Outputs: Node*.
        /*Node<int>* findSmallest(Node<int>* node) {

        }*/


        //Function: Starts the recursive process of printing the tree.
        //Inputs: None.
        //Outputs: None.
        void printTree() {
            preOrder(root);
        }

        //Function: Recursively prints the tree in pre order.
        //Inputs: Node* (root, or recursive node)
        //Outputs: None (prints the tree in order).
        void preOrder(Node<int>* node) {
            if (node != nullptr) {
                if (node->left != nullptr)
                    preOrder(node->left);
                cout << node->val << endl;
                if (node->right != nullptr)
                    preOrder(node->right);
            }
        }

        //Function: 
        //Inputs: 
        //Outputs: 
};