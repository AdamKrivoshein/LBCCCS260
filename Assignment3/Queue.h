#include "node.h"

template <class T>
class Queue {

    private:
        //variables
        node<T>* front;
        node<T>* back;

    public:
        Queue() {
            front = NULL;
        }

        void enqueue(T newVal) {
            node<T>* oldFront = front;
            front = new node<T>;
            front.value = newVal;
            if (oldFront != NULL)
                front.next = oldFront;
            else
                front.next = NULL;
            
            front = &newNode;
            //Basic working code:
            /*
            node<T> newNode;
            newNode.value = newVal;
            front = &newNode;
            */
        }

        void displayQueue() {
            std::cout << front->value << std::endl;
            std::cout << front->next << std::endl;
            /*if (front != NULL) {
                node<T>* current = front;
                while (current->next != NULL) {
                    std::cout << "Yes" << std::endl;
                    std::cout << current->value << std::endl;
                    current = current->next;
                }
            }*/
            //Basic working code:
            /*
            if (front != NULL) {
                std::cout << front->value << std::endl;
            }
            */
        }
};