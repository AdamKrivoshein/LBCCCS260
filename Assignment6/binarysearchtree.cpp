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
            //Find parent of node to be removed
            Node<int>* nodeParent = findNodeParent(root, val);
            Node<int>* removeNode;
            char side;
            
            //If removeNode is not root (In which case it can't have a parent)
            if (nodeParent != nullptr) {
                //Determine and store which child should be removed
                if (nodeParent->left != nullptr) {
                    if (nodeParent->left->val == val) {
                        removeNode = nodeParent->left;
                        side = 'l';
                    }
                }
                if (nodeParent->right != nullptr) {
                    if (nodeParent->right->val == val) {
                        removeNode = nodeParent->right;
                        side = 'r';
                    }
                }

                //1st Removal Case: Node has no children
                if (removeNode->left == nullptr && removeNode->right == nullptr) {
                    if (side == 'l')
                        nodeParent->left = nullptr;
                    else
                        nodeParent->right = nullptr;
                    delete removeNode;
                    return;
                }
            } 
            //Edge case when removeNode is root, but has no children
            else {
                removeNode = root;

                if (removeNode->left == nullptr && removeNode->right == nullptr) {
                    delete removeNode;
                    root = nullptr;
                    return;
                }
            }
            //2nd Removal Case: Node has children. Reorganizing is needed
            Node<int>* replacementNode;
            if (removeNode->left != nullptr) {
                if (removeNode->left->right != nullptr)
                    replacementNode = findLargest(removeNode->left);
                else {
                    replacementNode = removeNode->left;
                    if (removeNode->left->left != nullptr)
                        removeNode->left = removeNode->left->left;
                    else
                        removeNode->left = nullptr;
                }
            }
            else if (removeNode->right != nullptr) {
                if (removeNode->right->left != nullptr)
                    replacementNode = findSmallest(removeNode->right);
                else {
                    replacementNode = removeNode->right;
                    if (removeNode->right->right != nullptr)
                        removeNode->right = removeNode->right->right;
                    else
                        removeNode->right = nullptr;
                }
            }
            removeNode->val = replacementNode->val;
            delete replacementNode;

            return;
        }

        //Function: Finds and returns a node with a specified value.
        //Inputs: Node* (root or recursive node), int (value to be found)
        //Outputs: Node*
        Node<int>* findNodeParent(Node<int>* node, int val) {
            if (val < node->val) {
                if (node->left != nullptr) {
                    if (val != node->left->val)
                        return findNodeParent(node->left, val);
                    else
                        return node;
                }
                return nullptr;
            }
            else if (val > node->val) {
                if (node->right != nullptr) {
                    if (val != node->right->val)
                        return findNodeParent(node->right, val);
                    else
                        return node;
                }
                return nullptr;
            }
            return nullptr;
        }

        //Function: Finds & returns the largest node below the given node.
        //Inputs: Node* (The left node of a node to be removed, ONLY if the node passed has a child to the right)
        //Outputs: Node*.
        Node<int>* findLargest(Node<int>* node) {
            if (node->right != nullptr) {
                if (node->right->right != nullptr)
                    return findLargest(node->right);
                else {
                    Node<int>* tempNode = node->right;
                    if (node->right->left != nullptr)
                        node->right = node->right->left;
                    else
                        node->right = nullptr;
                    return tempNode;
                }
            }
            return nullptr;     //In theory this should never happen
        }

        //Function: Finds & returns the smallest node below the given node.
        //Inputs: Node* (The right node of a node to be removed, ONLY if the node passed has a child to the left)
        //Outputs: Node*.
        Node<int>* findSmallest(Node<int>* node) {
            if (node->left != nullptr) {
                if (node->left->left != nullptr)
                    return findLargest(node->left);
                else {
                    Node<int>* tempNode = node->left;
                    if (node->left->right != nullptr)
                        node->left = node->left->right;
                    else
                        node->left = nullptr;
                    return tempNode;
                }
            }
            return nullptr;     //In theory this should never happen
        }


        //Function: Starts the recursive process of printing the tree.
        //Inputs: None.
        //Outputs: None.
        void printTree() {
            preOrder(root);
            cout << endl;
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