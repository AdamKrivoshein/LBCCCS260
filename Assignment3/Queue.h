#include "node.h"

template <class T>
class Queue {

    private:
        //variables
        node<T>* front;
        node<T>* back;

    public:
        Queue() {
            front = new node<T>;
        }

}