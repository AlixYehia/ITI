#ifndef TREE_H
#define TREE_H

#include "Node.h"
using namespace std;

class Tree
{
    Node * root;

public:

    Tree() {
        root = NULL;
    }

    void add(int data){
        //Create Node
        Node * newNode = new Node(data);
        Node * parent = NULL;

        //1- NO Root First Node
        if(root == NULL){
            root = newNode;
        }
        else {
            Node * current = root;
            while(current != NULL) {
                parent = current;
                if(data > current->data) {
                    current = current->Right;
                }
                else {
                    current = current->Left;
                }
            }
            // Parent assignment
            if(data > parent->data) {
                parent->Right = newNode;
            }
            else {
                parent->Left = newNode;
            }
        }
    }

    Node * getNodeByData(int data){
        Node * current = root;
        while(current != NULL){
            if (data == current->data){
                return current;
            }
            if(data > current->data) {
                current = current->Right;
            }
            else {
                current = current->Left;
            }
        }
        return NULL;
    }

    int getDepth() {
        return getMaxDepth(root);  // Calls the private recursive method
    }

    void remove(int data){
        // Remove Pointers and Deallocate
        Node * current = getNodeByData(data);
        if(current == NULL)
            return;

        if (current == root) {
            if(root->Right == NULL && root->Left == NULL) {
                root = NULL;
            }
            else if(current->Right == NULL) {
                root = root->Left;
            }
            else if(current->Left == NULL) {
                root = root->Right;
            }
            else {
                Node * newRoot = root->Left;  //40
                Node * maxRight = getMaxRight(newRoot);  //45
                maxRight->Right = root->Right;  // 45->R=50->R(70)
                root = newRoot;
            }
        }
        else {
            // Node Without Children
            Node * parent = getParent(current);
            Node * child = NULL;
            if(current->Left == NULL && current->Right == NULL) {
                child = NULL;
            }
            // Node With Left Children Only
            else if(current->Right == NULL) {
                child = current->Left;
            }
            // Node With Right Children Only
            else if(current->Left == NULL) {
                child = current->Right;
            }
            // Node With Both Left & Right Children
            else {
                Node * NewParent = current->Left;  //30
                Node * maxRight = getMaxRight(NewParent);  //36
                maxRight->Right = current->Right;  //36-->43
                child = NewParent;
            }

            if(parent->Right == current) {
                parent->Right = child;
            }
            else {
                parent->Left = child;
            }
        }
        delete current;
    }

    void traverse() {
        display(root);
    }

    ~Tree() {}

protected:

private:

    void display(Node * node) {
        if(node == NULL)
            return;
        display(node->Left);  // 30
        cout << node->data << "  ";
        display(node->Right);  //
    }

    Node * getMaxRight(Node * current) {
        if(current != NULL) {
            while(current->Right != NULL) {
                current = current->Right;
            }
            return current;
        }
        return NULL;
    }

    Node * getParent(Node * current) {
        if(current != NULL) {
            Node * parent = root;

            while(parent != NULL) {
                if(parent->Left == current || parent->Right == current) {
                    return parent;
                }
                if(current->data > parent->data) {
                    parent = parent->Right;
                }
                else {
                    parent = parent->Left;
                }
            }
        }
        return NULL;
    }


    int getMaxDepth(Node* node) {
        if(node == NULL) {
            return 0;
        }

        int leftDepth = getMaxDepth(node->Left);
        int rightDepth = getMaxDepth(node->Right);

        return max(leftDepth, rightDepth) + 1;  // The depth is the greater of the two, plus 1 for the current node
    }
};

#endif // TREE_H
