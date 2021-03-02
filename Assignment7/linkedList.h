#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

template <class T>
class linkedList {

    private:
        node<T>* front;

    public:
        linkedList() {
            front = NULL;
        }

        //O(n)
        void add(T val, int index) {
            //If statement so doesn't contribute to big O complexity.
            if (index == 0) {
                node<T>* oldFront = front;
                front = new node<T>;
                front->val = val;
                front->next = oldFront;
            }
            //If statement so doesn't contribute to big O complexity.
            else if (front != NULL) {
                node<T>* currentNode = front;
                //For loop is O(n)
                //Iterating to node before index
                for (int i = 1; i < index; i++) {
                    if (currentNode->next != NULL)
                        currentNode = currentNode->next;
                    else
                        return;
                }
                //Creating and placing the new node
                node<T>* newNode = new node<T>;
                newNode->val = val;
                newNode->next = currentNode->next;
                currentNode->next = newNode;
            }
        }

        //O(n)
        T remove(int index) {
            T val = "";
            //If statement so doesn't contribute to big O complexity.
            if (front != NULL) {
                node<T>* currentNode = front;
                //If index is 0
                //If statement so doesn't contribute to big O complexity.
                if (index == 0) {
                    //If statement so doesn't contribute to big O complexity.
                    if (currentNode->next != NULL)
                        front = currentNode->next;
                    val = currentNode->val;
                    delete currentNode;
                    return val;
                }
                //Iterating through the list, finding the node before the one to be removed.
                //For loop is O(n)
                for (int i = 1; i < index; i++) {
                    if (currentNode->next != NULL)
                        currentNode = currentNode->next;
                    else
                        return val;
                }
                //If statement so doesn't contribute to big O complexity.
                //Removing the node...
                if (currentNode->next != NULL) {
                    node<T>* removedNode = currentNode->next;
                    val = removedNode->val;
                    currentNode->next = removedNode->next;
                    delete removedNode;
                    return val;
                } else {
                    return val;
                }
            }
            return val;
        }

        //O(n)
        bool contains(T val) {
            node<T>* currentNode = front;

            while (currentNode != NULL) {
                if (currentNode->val == val)
                    return true;
                currentNode = currentNode->next;
            }

            return false;
        }

        //Strictly for testing purposes only
        //O(n)
        void displayList() {
            node<T>* currentNode = front;
            //If statement so doesn't contribute to big O complexity.
            if (currentNode != NULL) {
                cout << currentNode->val << endl;
                //While loop is O(n)
                while (currentNode->next != NULL) {
                    currentNode = currentNode->next;
                    cout << currentNode->val << endl;
                }
            }
        }
};