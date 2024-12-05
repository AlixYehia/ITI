#include <iostream>
#include "Tree.h"

int main() {
    Tree myTree;

    // Add nodes to the tree
    myTree.add(50);
    myTree.add(30);
    myTree.add(70);
    myTree.add(20);
    myTree.add(40);
    myTree.add(60);
    myTree.add(80);
    myTree.add(90);

    int depth;

    depth = myTree.getDepth();
    cout << "The max depth of the tree is: " << depth << endl;

    return 0;
}
