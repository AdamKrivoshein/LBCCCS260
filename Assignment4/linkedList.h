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

        void add(T val, int index) {
            if (front == NULL && index == 0) {
                front = new node<T>;
                front->val = val;
                front->next = NULL;
            }
            else if (index == 0 && front != NULL) {
                node<T>* oldFront = front;
                front = new node<T>;
                front->val = val;
                front->next = oldFront;
            }
            else if (front != NULL) {
                node<T>* currentNode = front;
                for (int i = 1; i < index; i++) {
                    if (currentNode->next != NULL)
                        currentNode = currentNode->next;
                    else
                        return;
                }
                if (currentNode->next != NULL) {
                    node<T>* newNode = new node<T>;
                    newNode->val = val;
                    newNode->next = currentNode->next;
                    currentNode->next = newNode;
                }
                else {
                    node<T>* newNode = new node<T>;
                    newNode->val = val;
                    newNode->next = NULL;
                    currentNode->next = newNode;
                }
            }
        }

        int remove(int index) {
            if (front != NULL) {
                node<T>* currentNode = front;
                if (index == 0) {
                    if (currentNode->next != NULL)
                        front = currentNode->next;
                    int val = currentNode->val;
                    delete[] currentNode;
                    return val;
                }
            }

            return front->val;
        }

        void displayList() {
            node<T>* currentNode = front;
            if (currentNode != NULL) {
                cout << currentNode->val << endl;
                while (currentNode->next != NULL) {
                    currentNode = currentNode->next;
                    cout << currentNode->val << endl;
                }
            }
        }
};