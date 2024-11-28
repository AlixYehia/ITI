#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Node.h"

// Swap data between two nodes
void swapData(Node* node1, Node* node2)
{
    int temp = node1->Data;
    node1->Data = node2->Data;
    node2->Data = temp;
}

/// Bubble Sort function to sort the linked list
void bubbleSort(Node* head)
{
    if (!head) return;  // If the list is empty, no need to sort

    bool swapped;
    Node* current;
    Node* lastSorted = NULL;

    do {
        swapped = false;
        current = head;

        // Traverse the list from head to tail
        while (current && current->Next != lastSorted)
        {
            if (current->Data > current->Next->Data)
            {
                swapData(current, current->Next);
                swapped = true;
            }
            current = current->Next;
        }
        lastSorted = current;  // After each pass, the last node is sorted
    } while (swapped);  // Repeat the process if any swap was made
}

#endif // BUBBLESORT_H
