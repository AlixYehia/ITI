#include <iostream>
using namespace std;

#include "Queue.h"

int main() {
    CircularQueue queue(5);

    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    queue.enQueue(40);
    queue.enQueue(50);


    cout << "Queue after enQueue operations: ";
    queue.display();


    // Attempt to enqueue full queue
    queue.enQueue(60);


    int data;
    queue.deQueue(data);
    cout << "Dequeued: " << data << endl;
    queue.deQueue(data);
    cout << "Dequeued: " << data << endl;


    cout << "Queue after deQueue operations: ";
    queue.display();


    queue.getFront(data);
    cout << "Front element: " << data << endl;
    queue.getRear(data);
    cout << "Rear element: " << data << endl;

    return 0;
}
