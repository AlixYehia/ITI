#include <iostream>

using namespace std;

class Queue {
private:
    int* Q;            // Array to store queue elements
    int Head;          // Index of the front element
    int Tail;          // Index of the next available position
    int capacity;      // Maximum capacity of the queue
    bool isCircular;   // Toggle between circular and shifting mode

public:
    // Parameterless constructor (default size, circular by default)
    Queue(int size = 10, bool circular = true) : capacity(size), isCircular(circular), Head(-1), Tail(-1)
        {
            Q = new int[capacity];
        }

    // Destructor to free allocated memory
    ~Queue()
    {
        delete[] Q;
    }

    // Check if the queue is full
    bool IsFull() const
    {
        if (isCircular)
        {
            return (Tail + 1) % capacity == Head;
        }
        else
        {
            return Tail == capacity - 1;
        }
    }

    // Check if the queue is empty
    bool IsEmpty() const
    {
        return Head == -1;
    }

    // Enqueue function to add an element to the queue
    void EnQueue(int value)
    {
        if ( IsFull() )
        {
            cout << "Queue is full, cannot enqueue " << value << ".\n";
            return;
        }

        if (IsEmpty())
        {
            Head = Tail = 0;
        }
        else
        {
            if (isCircular)
            {
                Tail = (Tail + 1) % capacity;
            }
            else
            {
                Tail++;
            }
        }

        Q[Tail] = value;
    }

    // Dequeue function to remove and return the front element
    int DeQueue()
    {
        if (IsEmpty())
        {
            std::cerr << "Queue is empty, cannot dequeue.\n";
            return -1; // Or throw an exception
        }

        int dequeuedValue = Q[Head];

        if (Head == Tail)  // Queue becomes empty after dequeuing
        {
            Head = Tail = -1;
        }
        else
        {
            if (isCircular)
            {
                Head = (Head + 1) % capacity;
            }
            else
            {
                // Shift all elements if in shifting mode
                for (int i = 0; i < Tail; i++)
                {
                    Q[i] = Q[i + 1];
                }

                Tail--; // Move Tail back by one after shifting
            }
        }

        return dequeuedValue;
    }
};

// Example usage
int main() {
    Queue q(5); // Create a queue with capacity 5 and circular by default

    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);

    std::cout << "Dequeued: " << q.DeQueue() << std::endl;
    std::cout << "Dequeued: " << q.DeQueue() << std::endl;

    q.EnQueue(6);  // Circular behavior allows reusing space
    q.EnQueue(7);

    // Display all elements remaining in the queue
    while (!q.IsEmpty()) {
        std::cout << "Dequeued: " << q.DeQueue() << std::endl;
    }

    return 0;
}
