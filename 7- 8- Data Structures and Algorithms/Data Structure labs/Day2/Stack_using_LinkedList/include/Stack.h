#ifndef STACK_H
#define STACK_H

#include "Node.h"

/// Implementing stack operations using linked list
class Stack {
private:
    Node* top;

public:
    // Constructor (No need for a size parameter in a linked list-based stack)
    Stack() {
        top = NULL;
    }


    bool isEmpty() {
        return top == NULL;
    }


    bool push(int data) {
        Node* newNode = new Node(data);
//        if (!newNode) {   Advanced check
//            return false; // Failed to allocate memory
//        }
        newNode->next = top;
        top = newNode;
        return true;
    }


    bool pop(int &data) {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return false;
        }
        Node* temp = top;
        data = top->data;
        top = top->next;
        delete temp;
        return true;
    }


    bool peek(int &data) {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return false;
        }
        data = top->data;
        return true;
    }


/// top -> [30] -> [20] -> [10] -> NULL   next points to the previous elements (reversed for the stack using pointer)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements:\n";
        while (temp != NULL) {
            cout << temp->data << "\n";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            int data;
            pop(data);  // Deallocate all nodes
        }
    }
};

#endif // STACK_H
