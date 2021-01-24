#include <iostream>
#include "queue.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Queue<int> myQueue;

    myQueue.displayQueue();
    myQueue.enqueue(1);
    myQueue.displayQueue();
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.displayQueue();

    return 0;
}