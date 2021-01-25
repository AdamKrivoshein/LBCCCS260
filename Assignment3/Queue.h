#include "node.h"

using std::cout;
using std::endl;

template <class T>
class Queue {

    private:
        node<T>* front;
        node<T>* back;

    public:
        Queue() {
            front = NULL;
            back = NULL;
        }

        //O(1)
        void enqueue(T newVal) {
            if (back != NULL) {
                node<T>* oldBack = back;
                back = new node<T>;
                back->val = newVal;
                back->next = NULL;
                oldBack->next = back;
            } else {
                back = new node<T>;
                front = back;
                back->val = newVal;
                back->next = NULL;
            }
        }

        //O(1)
        T dequeue() {
            T returnVal = -1;
            if (front != NULL) {
                returnVal = front->val;
                if (front->next != NULL) {
                    front = front->next;
                } else {
                    front = NULL;
                    back = NULL;
                }
            }
            return returnVal;
        }

        //O(n)
        //Only for verification purposes
        void displayQueue() {
            if (front != NULL) {
                cout << "Printing queue..." << endl;
                node<T>* current = front;
                cout << current->val << endl;
                while (current->next != NULL) {
                    current = current->next;
                    cout << current->val << endl;
                }
            }
        }
};