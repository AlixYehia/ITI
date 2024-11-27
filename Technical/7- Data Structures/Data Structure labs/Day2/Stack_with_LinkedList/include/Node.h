#ifndef NODE_H
#define NODE_H


class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}  /// Constructor
};

#endif // NODE_H
