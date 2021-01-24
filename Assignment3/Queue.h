#include "node.h"

using std::cout;
using std::endl;

template <class T>
class Queue {

    private:
        //variables
        node<T>* front;
        node<T>* back;

    public:
        Queue() {
            front = NULL;
            back = NULL;
        }

        void enqueue(T newVal) {
            if (back != NULL) {
                node<T>* oldBack = back;
                back = new node<T>;
                back->val = newVal;
                back->next = NULL;
                oldBack->next = back;
                std::cout << back->val << std::endl;
            } else {
                back = new node<T>;
                front = back;
                back->val = newVal;
                std::cout << front->val << std::endl;
            }
        }

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