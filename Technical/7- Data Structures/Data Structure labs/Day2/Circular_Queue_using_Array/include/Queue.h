#ifndef QUEUE_H
#define QUEUE_H


class CircularQueue {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    /// Constructor to initialize the queue with a given size
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }


    bool isFull() {
        return (rear + 1) % size == front;
    }


    bool isEmpty() {
        return front == -1;
    }


    bool enQueue(int data) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue data" << endl;
            return false;
        }
        if (front == -1) {  // If queue is empty
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
        return true;
    }


    bool deQueue(int &data) {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue data" << endl;
            return false;
        }
        data = arr[front];
        if (front == rear) {  // Only one element left, reset the queue
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;
    }


    bool getFront(int &data) {
        if (isEmpty()) {
            cout << "Queue is empty, cannot get front data" << endl;
            return false;
        }
        data = arr[front];
        return true;
    }


    bool getRear(int &data) {
        if (isEmpty()) {
            cout << "Queue is empty, cannot get rear data" << endl;
            return false;
        }
        data = arr[rear];
        return true;
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl; // Print the rear element
    }


    ~CircularQueue() {
        delete[] arr;
    }
};

#endif // QUEUE_H
