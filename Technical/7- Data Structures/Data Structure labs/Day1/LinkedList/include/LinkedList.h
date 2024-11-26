#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}  /// Constructor
};

class LinkedList
{
private:
    Node* head;  /// Pointer to the first node in the list. If the list is empty, head is NULL.

public:
    LinkedList() : head(NULL) {}    /// Initialization Constructor which head points to null since still empty

    ~LinkedList()
    {
        Node* current = head;
        while (current)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void InsertAfter(int data, int afterData)
    {
        Node* current = head;
        while (current != NULL && current->data != afterData)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Node with value " << afterData << " not found." << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }

    void InsertBefore(int data, int beforeData)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == beforeData)
        {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != beforeData)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "Node with value " << beforeData << " not found." << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }

    int Getcounter() const
    {
        int counter = 0;
        Node* current = head;
        while (current != NULL)
        {
            counter++;
            current = current->next;
        }
        return counter;
    }

    int GetDataByIndex(int index) const
    {
        if (index < 0)
        {
            cout << "Invalid index." << endl;
            return -1;
        }
        int counter = 0;
        Node* current = head;
        while (current != NULL)
        {
            if (counter == index)
            {
                return current->data;     /// exit if found
            }
            counter++;
            current = current->next;
        }
        cout << "Index out of range." << endl;
        return -1;
    }

    void Display() const
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void Append(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
};

#endif // LINKEDLIST_H_INCLUDED
